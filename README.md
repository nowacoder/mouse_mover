# mouse_mover
Randomly move mouse to avoid Windows goes to idle.

- Inspired by the `win32api` from [pyWin32](https://mhammond.github.io/pywin32/modules.html)
- Using the [SendInput](https://docs.microsoft.com/en-us/windows/win32/api/winuser/nf-winuser-sendinput) function instead of SetCursorPos, because SendInput can emulate a true mouse event which resets the Windows idle timer but SetCursorPos only moves the cursor.
  + Uses [MOUSEINPUT](https://docs.microsoft.com/en-us/windows/win32/api/winuser/ns-winuser-mouseinput) structure.
- Potentially, [SetThreadExecutionState](https://docs.microsoft.com/en-us/windows/win32/api/winbase/nf-winbase-setthreadexecutionstate) may also do the work. Didn't try.
