Talk("薛神醫？", 0, 1);
Talk("這位小兄弟今天來不知是．．．．", 45, 0);
if AskJoin () == true then goto label0 end;
    Talk("薛神醫名頭大的很，看來你混的不錯．", 0, 1);
    exit();
::label0::
    Talk("要不要跟我一起混啊，包你吃香喝辣．", 0, 1);
    Talk("我不需要，你離開吧．", 45, 0);
    Talk("干，是在堅持什麼", 0, 0);
exit();
