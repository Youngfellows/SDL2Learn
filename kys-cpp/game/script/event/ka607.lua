Talk("那里來的小子，敢擅闖我神龍島．", 97, 0);
Talk("神龍島？聽起來好像頗棘手的，我還是下回有把握點再來．", 0, 1);
Talk("想走，我神龍島可不是你說來就來，說走就走的．", 97, 0);
Talk("別這樣嘛！我船隨便開開，就開到你們島上了．本想看看你們這邊有沒有我要找的書，但．．我看大概沒有．．．打擾了．．．", 0, 1);
Talk("果然是來偷書的．來人呀！快將他拿下．", 97, 0);
if TryBattle(94) == true then goto label0 end;
    Dead();
    exit();
::label0::
    ModifyEvent(-2, 5, 0, 0, -1, -1, -1, -1, -1, -1, -2, -2, -2);
    ModifyEvent(-2, 6, 0, 0, -1, -1, -1, -1, -1, -1, -2, -2, -2);
    ModifyEvent(-2, 7, 0, 0, -1, -1, -1, -1, -1, -1, -2, -2, -2);
    ModifyEvent(-2, 8, 0, 0, -1, -1, -1, -1, -1, -1, -2, -2, -2);
    ModifyEvent(-2, 9, 0, 0, -1, -1, -1, -1, -1, -1, -2, -2, -2);
    ModifyEvent(-2, 10, 0, 0, -1, -1, -1, -1, -1, -1, -2, -2, -2);
    LightScence();
    Talk("踏破鐵鞋無覓處，得來全不費功夫．這里或許有我要找的書，進去找他們老大要．", 0, 1);
    AddFame(1);
exit();