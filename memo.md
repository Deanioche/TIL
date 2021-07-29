# memo

## **vscode 터미널 현재파일 경로로 이동시키는 단축키 설정**

keybindings.json에서
```json
{
    "key": "alt+`",
    "command": "workbench.action.terminal.sendSequence",
    "args": {
        "text": "cd \"${fileDirname}\"\u000D"
    }
}
```
추가하면 알트 + ` 버튼으로 경로가 바뀜.

${fileDirname} : 파일 경로
\u000D : 엔터키 입력