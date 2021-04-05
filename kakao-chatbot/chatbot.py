import time, win32con, win32api, win32gui

# # 카톡창 이름 (열려있는 상태, 최소화 X, 창뒤에 숨어있는 비활성화 상태 가능)
kakao_opentalk_name = 'PIPI38'


def kakao_sendtext(text):
    win32api.SendMessage(hwndEdit, win32con.WM_SETTEXT, 0, text)
    SendReturn(hwndEdit)


# # 엔터
def SendReturn(hwnd):
    win32api.PostMessage(hwnd, win32con.WM_KEYDOWN, win32con.VK_RETURN, 0)
    time.sleep(0.01)
    win32api.PostMessage(hwnd, win32con.WM_KEYUP, win32con.VK_RETURN, 0)



def timer(sec, command):
    kakao_sendtext(command)
    for i in range(sec):
        print("타이머 : ", (sec - i))
        time.sleep(1)




# # 핸들
hwndMain = win32gui.FindWindow(None, kakao_opentalk_name)
hwndEdit = win32gui.FindWindowEx(hwndMain, None, "RICHEDIT50W", None)
hwndListControl = win32gui.FindWindowEx(hwndMain, None, "EVA_VH_ListControl_Dblclk", None)

# # 채팅 전송
text = "*사냥"
text2 = "*구매 0"
# text = "*구매 2" # 2000
# for i in range(1):
#     for j in range(43):
#         kakao_sendtext(text)
#         print(j, i)
#         time.sleep(0.5)
#     time.sleep(3)
#     kakao_sendtext("*내정보")
#     time.sleep(3)
#     timer(50, "*회복")
#     kakao_sendtext("*내정보")
#     time.sleep(3)


while(1):
    kakao_sendtext("*길드공격 1");
    time.sleep(0.3);
    
print("종료")
# 427135 𝔾


'''

*내정보
*스탯포인트
*스탯 올리기 공격 5
*스탯 올리기 체력 5
*스탯 올리기 공격 5
'''
