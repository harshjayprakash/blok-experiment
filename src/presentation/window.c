#include "window.h"

static int window_action_while_running(HWND window_handle, WPARAM word_param, LPARAM long_param)
{
}
static int window_action_on_close(HWND window_handle, WPARAM word_param, LPARAM long_param)
{
}

static long long window_callback(
    HWND window_handle, 
    UINT message, 
    WPARAM word_param, 
    LPARAM long_param)
{
}

static int window_message_loop(window *wnd)
{
    if (wnd == NULL)
        return -1;
    
    while (GetMessageW(&wnd->window_message, NULL, 0, 0))
    {
        TranslateMessage(&wnd->window_message);
        DispatchMessageW(&wnd->window_message);
        window_action_while_running(
            wnd->window_handle, wnd->window_message.wParam, wnd->window_message.lParam);
    }
    return (int) wnd->window_message.wParam;
}

static ATOM window_register(window *wnd)
{
    if (wnd == NULL)
        return -1;
    
    (void) wcsncpy(wnd->window_class_name, L"blok_window_class", CHAR_LENGTH_COUNT);

    wnd->window_class.cbSize = sizeof(WNDCLASSEXW);
    wnd->window_class.style = CS_HREDRAW | CS_VREDRAW;
    wnd->window_class.lpfnWndProc = window_callback;
    wnd->window_class.cbClsExtra = 0;
    wnd->window_class.cbWndExtra = 0;
    wnd->window_class.hInstance = program_instance_get()->instance_handle;
    wnd->window_class.hIcon = LoadIcon(wnd->window_class.hInstance, IDI_APPLICATION);
    wnd->window_class.hCursor = LoadCursor(NULL, IDC_ARROW);
    wnd->window_class.hbrBackground = CreateSolidBrush(RGB(0, 0, 0));
    wnd->window_class.lpszMenuName = NULL;
    wnd->window_class.lpszClassName = wnd->window_class_name;
    wnd->window_class.hIconSm = LoadIcon(wnd->window_class.hInstance, IDI_APPLICATION);

    return RegisterClassExW(&wnd->window_class);
}

static int window_create(window *wnd)
{
    if (wnd == NULL)
        return -1;
    
    wnd->window_handle = CreateWindowExW(
        WS_EX_OVERLAPPEDWINDOW,
        wnd->window_class_name,
        L"The Experimental Block Project.",
        WS_OVERLAPPEDWINDOW,
        CW_USEDEFAULT, CW_USEDEFAULT,
        800, 600,
        NULL,
        NULL,
        program_instance_get()->instance_handle,
        NULL
    );

    if (!wnd->window_handle)
        return 1;
    
    return 0;
}

optional_window window_new(void)
{
    optional_window opt_wnd;
    window wnd;

    opt_wnd.registered = window_register(&wnd);
    if (opt_wnd.registered == 0)
    {
        window_free(&wnd);
        return opt_wnd;
    }

    opt_wnd.created = window_create(&wnd) + 1;
    if (opt_wnd.created != 1)
    {
        window_free(&wnd);
        return opt_wnd;
    }

}

void window_free(window *wnd)
{

}