#include "GUI.h"
#include "WM.h"
#include "DIALOG_intern.h"
#include "FRAMEWIN.h"
#include "BUTTON.h"
#include "TEXT.h"
#include "TREEVIEW.h"
#include "bsp_led.h"
#include <string.h>
#include "stdio.h"

#define ID_FRAMEWIN_0 (GUI_ID_USER + 0x00)
#define ID_BUTTON_0 (GUI_ID_USER + 0x01)
#define ID_BUTTON_1 (GUI_ID_USER + 0x02)
#define ID_BUTTON_2 (GUI_ID_USER + 0x03)
#define ID_BUTTON_3 (GUI_ID_USER + 0x04)
#define ID_BUTTON_4 (GUI_ID_USER + 0x05)
#define ID_BUTTON_5 (GUI_ID_USER + 0x06)
#define ID_BUTTON_6 (GUI_ID_USER + 0x07)
#define ID_BUTTON_7 (GUI_ID_USER + 0x08)
#define ID_BUTTON_8 (GUI_ID_USER + 0x09)
#define ID_BUTTON_9 (GUI_ID_USER + 0x0A)
#define ID_TEXT_0   (GUI_ID_USER + 0x0B)
#define ENTER (GUI_ID_USER + 0x0C)

static const GUI_WIDGET_CREATE_INFO _aDialogCreate[] = {
    { FRAMEWIN_CreateIndirect, "Framewin", ID_FRAMEWIN_0, 0, 0, 240,
    320, 0, 0x0, 0 },
    { BUTTON_CreateIndirect, "Button0", ID_BUTTON_0, 15, 30, 60, 50,
    0, 0x0, 0 },
    { BUTTON_CreateIndirect, "Button1", ID_BUTTON_1, 90, 30, 60, 50,
    0, 0x0, 0 },
		{ BUTTON_CreateIndirect, "Button2", ID_BUTTON_2, 165, 30, 60, 50,
    0, 0x0, 0 },
		{ BUTTON_CreateIndirect, "Button3", ID_BUTTON_3, 15, 100, 60, 50,
    0, 0x0, 0 },
    { BUTTON_CreateIndirect, "Button4", ID_BUTTON_4, 90, 100, 60, 50,
    0, 0x0, 0 },
		{ BUTTON_CreateIndirect, "Button5", ID_BUTTON_5, 165, 100, 60, 50,
    0, 0x0, 0 },
		{ BUTTON_CreateIndirect, "Button6", ID_BUTTON_6, 15, 170, 60, 50,
    0, 0x0, 0 },
    { BUTTON_CreateIndirect, "Button7", ID_BUTTON_7, 90, 170, 60, 50,
    0, 0x0, 0 },
		{ BUTTON_CreateIndirect, "Button8", ID_BUTTON_8, 165, 170, 60, 50,
    0, 0x0, 0 },
		{ BUTTON_CreateIndirect, "Button9", ID_BUTTON_9, 90, 240, 60, 50,
    0, 0x0, 0 },
		{ BUTTON_CreateIndirect, "ENTER", ENTER, 165, 240, 60, 50,
    0, 0x0, 0 },
		{ TEXT_CreateIndirect, "Text0", ID_TEXT_0, 10, 10, 200, 20, 0,
    0x0, 0 },
};

WM_HWIN CreateFramewin(void);
static void _cbDialog(WM_MESSAGE *pMsg);
static void _cbButton0(WM_MESSAGE *pMsg);
static void _cbButton1(WM_MESSAGE *pMsg);
static void _cbButton2(WM_MESSAGE *pMsg);
static void _cbButton3(WM_MESSAGE *pMsg);
static void _cbButton4(WM_MESSAGE *pMsg);
static void _cbButton5(WM_MESSAGE *pMsg);
static void _cbButton6(WM_MESSAGE *pMsg);
static void _cbButton7(WM_MESSAGE *pMsg);
static void _cbButton8(WM_MESSAGE *pMsg);
static void _cbButton9(WM_MESSAGE *pMsg);
static void _ENTER(WM_MESSAGE *pMsg);
void CreateFramewin_task(void* parameter);
void show_key(TREEVIEW_ITEM_Handle hItem);
int compare_key();