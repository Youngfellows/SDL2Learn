ModifyEvent(-2, -2, 1, 1, -1, -1, -1, 2608, 2608, 2608, -2, -2, -2);
AddItem(72, 1);
Talk("把《金蛇秘籍》交給我！道爺今日饒你不死。", 7, 0);
Talk("好大的口氣，有本事就來拿吧！", 0, 1);
Talk("好小子，你是第一個敢這麼跟我玉真子說話的人。", 7, 0);
if TryBattle(156) == true then goto label0 end;
    Dead();
    exit();
::label0::
    AddFame(3);
exit();
