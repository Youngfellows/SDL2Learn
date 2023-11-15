Talk("沒事就快走吧，別在此逗留．", 7, 0);
Talk("在下有個請求，請何掌門能放了那位可憐的大夫．", 0, 1);
Talk("這個庸醫，還妄稱是陜，甘一帶最有名的大夫，連是什麼病都說不出來．若是他醫不好五姑的病，我就一刀把他砍了，免得留在世上招搖撞騙，荼害世人．", 7, 0);
if AskBattle() == true then goto label0 end;
    Talk("說的也是，在下告辭了．", 0, 1);
    ModifyEvent(-2, -2, -2, -2, 139, -1, -1, -2, -2, -2, -2, -2, -2);
    exit();
::label0::
    Talk("可是他實在是已盡了力，況且那女人長的這麼丑，不要也罷．", 0, 1);
    Talk("你說什麼！", 7, 0);
    Talk("糟了，說溜了嘴．", 0, 1);
    if TryBattle(18) == true then goto label1 end;
        Dead();
        exit();
::label1::
        LightScence();
        Talk("．．．．．", 7, 0);
        ModifyEvent(-2, 8, 0, 0, -1, -1, -1, -1, -1, -1, -2, -2, -2);
        ModifyEvent(-2, -2, -2, -2, 165, -1, -1, -2, -2, -2, -2, -2, -2);
        AddMorality(2);
        AddFame(3);
exit();
