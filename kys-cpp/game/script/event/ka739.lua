Talk("<我要想辦法救出蘇普的未婚妻。>", 200, 0);
Talk("客人辛苦了，在沙漠中旅行是一件很辛苦的事。", 0, 5);
Talk("你是小時候常來這里跟文秀玩的那個小子?", 200, 0);
if TryBattle(261) == true then goto label0 end;
    Dead();
    exit();
::label0::
    LightScence();
    Talk("小子，鬼鬼祟祟來到這廢墟做什麼?", 200, 0);
    Talk("你在這做什麼我就做什麼．", 0, 5);
    Talk("果然又是個尋找高昌迷宮入口的人，去死吧!", 200, 0);
    Talk("小子，你武功不錯，要不要跟我一起尋找高昌迷宮入口 ，順便干掉其他肖想高昌迷宮寶物的人，得到寶物五五分帳如何?", 0, 5);
    Talk("去!<挖鼻孔>", 200, 0);
    Talk("好，我虧一點好了，六四!", 0, 5);
    Talk("ZZZZZZZZ", 200, 0);
    if TryBattle(261) == true then goto label1 end;
        Dead();
        exit();
::label1::
        ModifyEvent(-2, -2, 0, -2, -1, -1, -1, -1, -1, -1, -2, -2, -2);
        LightScence();
        Talk("好，我虧血本跳樓大拍賣，七三!再來就不可能了．", 0, 0);
        if InTeam(49) == false then goto label2 end;
            Talk("九一!!你他媽的還是人嗎?我跟你同歸於盡．", 49, 0);
::label2::
            ModifyEvent(89, 0, 1, -2, 737, -1, -1, 6806, 6806, 6806, -2, -2, -2);
            ModifyEvent(89, 2, 0, -2, -1, -1, 738, -2, -2, -2, -2, -2, -2);
            ModifyEvent(89, 3, 1, -2, 736, -1, -1, 6066, 6066, 6066, -2, -2, -2);
exit();
