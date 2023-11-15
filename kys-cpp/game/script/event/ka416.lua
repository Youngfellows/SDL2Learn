if InTeam(56) == true then goto label0 end;
    exit();
::label0::
    Talk("他媽的，四周都是黑泥，這鬼地方要怎麼進去啊！", 0, 1);
    Talk("大哥，看來此潭的主人精通五行八卦，大哥你向右前方斜角走十七步，向左走八步，再向右斜行十三步，應該就能通過此潭了。", 137, 5);
    DarkScence();
    ChangeSubMapPic(-2, 0, 994, 990);
    LightScence();
    ModifyEvent(-2, -2, -2, -2, -1, -1, -1, -1, -1, -1, -2, -2, -2);
    ModifyEvent(-2, 5, -2, -2, -1, -1, 434, -1, -1, -1, -2, -2, -2);
exit();
