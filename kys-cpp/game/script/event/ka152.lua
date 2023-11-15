if InTeam(9) == false then goto label0 end;
    if HaveItemBool(113) == false then goto label1 end;
        if HaveItemBool(9) == false then goto label2 end;
            Talk("歡迎閣下來到武當山，請隨意參觀．若有武學上的疑惑，可與家師討論．家師定樂於與各位聊聊．", 76, 0);
            exit();
::label2::
            Talk("不好了無忌。太師夫被人偷襲，受傷不輕！", 76, 0);
            Talk("什么！？", 9, 1);
exit();
::label0::
::label1::
            Talk("歡迎閣下來到武當山，請隨意參觀．若有武學上的疑惑，可與家師討論．家師定樂於與各位聊聊．", 76, 0);
exit();
