if AskRest() == true then goto  label0 end;
    exit();
::label0::
    Talk("為了走更遠的路，適當的OGC也是必須的．我就好好的睡一覺吧！", 0, 1);
    DarkScence();
    Rest();
    SetTowards(3);
    LightScence();
    Talk("一覺起來，一柱擎天．國旗都昇起來了，地圖也都畫好了，走吧，繼續冒險去了！", 0, 1);
exit();
