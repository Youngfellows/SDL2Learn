Talk("我們一起去瞧瞧，到底世上是不是真有一座高昌迷宮．", 195, 0);
if AskJoin () == true then goto label0 end;
    Talk("李姑娘，你先回去計老頭的小屋，有需要我會去找你幫忙．", 0, 5);
    exit();
::label0::
    if TeamIsFull() == false then goto label1 end;
        Talk("你的隊伍已滿，我無法加入．", 195, 0);
        exit();
::label1::
        Talk("我要去高昌迷宮，要跟我一起去嗎?", 0, 5);
        Talk("姑娘一直呆在大漠不會無聊嗎?隨我闖蕩江湖吧!", 195, 0);
        DarkScence();
        ModifyEvent(-2, -2, 0, -2, -1, -1, -1, -1, -1, -1, -2, -2, -2);
        LightScence();
        Join(42);
exit();
