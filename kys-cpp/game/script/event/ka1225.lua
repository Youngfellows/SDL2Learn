if InTeam(49) == false then goto label0 end;
    Talk("宮主，需要休息嗎?奴婢替你寬衣侍寢。", 59, 1);
    if AskRest() == true then goto  label1 end;
        Talk("老妖婆，看來你的功力都恢復了，疑?你怎麼會有那枚戒指。", 49, 5);
        Talk("．．．．．．", 0, 0);
        exit();
::label1::
        Talk("當然，梅蘭竹菊一起來，有春夏秋冬更好，湊成八仙過海十六臺爽歪歪。", 49, 5);
        Talk("是，宮主。", 59, 1);
        Talk("你還站在這里做什麼?", 49, 5);
        Talk("俗話說的好，有福同享，有難同當，我們一同經歷了這麼多困難，如今兄弟有肉吃了，也該分點骨頭給我吧!", 0, 0);
        Talk("女人如衣服，朋友如手足，誰穿我衣服，我砍他手足 滾。", 49, 5);
        Talk("．．．．．．", 0, 0);
        DarkScence();
        Rest();
        LeaveTeam(49);
        OldSetScencePosition(40, 40);
        ModifyEvent(-2, 0, 1, -2, 1226, -1, -1, 6578, 6578, 6578, -2, -2, -2);
        LightScence();
        Talk("媽的，居然還真的不管我把我趕出來，他爽了一夜我卻在這吃大便。", 0, 0);
        exit();
::label0::
        Talk("．．．．．．", 59, 0);
exit();
