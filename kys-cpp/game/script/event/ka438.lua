Talk("楊兄，長年待在這古墓中，你受的了嗎？", 0, 1);
Talk("習慣就好了，龍兒還從小就住在這呢，這是我們古墓派的傳統．", 118, 0);
Talk("兄弟近來如何？", 0, 1);
ModifyEvent(-2, -2, -2, -2, 439, -1, -1, -2, -2, -2, -2, -2, -2);
if AskJoin () == true then goto label0 end;
    Talk("一切順利，你夫婦倆可還好吧．", 0, 1);
    Talk("托你的福，一切還好．", 118, 0);
    exit();
::label0::
    Talk("近日旅途有些不順，此次前來是想請楊兄加入，助我一臂之力．", 0, 1);
    Talk("那有什麼問題，別的沒有，就是有”一臂”．", 118, 0);
    Talk("楊兄說笑了．", 0, 1);
    Talk("那就走吧．", 0, 1);
    if TeamIsFull() == false then goto label1 end;
        Talk("你的隊伍已滿，我無法加入．", 118, 0);
        exit();
::label1::
        DarkScence();
        ModifyEvent(-2, -2, 0, 0, -1, -1, -1, -1, -1, -1, -2, -2, -2);
        LightScence();
        Join(58);
exit();
