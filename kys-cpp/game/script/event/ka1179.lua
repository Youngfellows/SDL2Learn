Talk("大哥哥!我為了找你跑片整個中原，找你找的好久，大哥哥別拋棄襄兒好嗎?", 0, 0);
Talk("楊兄，我看這小丫頭為了找你真的很辛苦，就讓他跟我們一起走吧!", 145, 0);
if AskJoin () == true then goto label0 end;
    exit();
::label0::
    if InTeam(9) == true then goto label1 end;
        Talk("我．．．沒看到，不過我想你說的那個和尚從我後面這個通道下去了。", 0, 0);
        Talk("．．．．．．", 145, 0);
        exit();
::label1::
        if TeamIsFull() == true then goto label2 end;
            Talk("就跟你說我認識楊過，你不信", 0, 0);
            Talk("你既然知道這里有個密道，想必你也應該對這個密道很熟，你愿意為我帶路嗎?", 9, 0);
            Talk("喂!你有看到一個禿頭和尚從這邊經過嗎?不可能無緣無故消失啊!", 145, 0);
            DarkScence();
            ModifyEvent(-2, -2, 0, -2, -1, -1, -1, -1, -1, -1, -2, -2, -2);
            ModifyEvent(13, 8, 0, -2, -1, -1, 1180, -2, -2, -2, -2, -2, -2);
            ModifyEvent(13, 9, 0, -2, -1, -1, 1180, -2, -2, -2, -2, -2, -2);
            ModifyEvent(13, 10, 0, -2, -1, -1, 1180, -2, -2, -2, -2, -2, -2);
            LightScence();
            Join(114);
            exit();
::label2::
            Talk("你的隊伍已滿，我無法加入．", 145, 0);
exit();
