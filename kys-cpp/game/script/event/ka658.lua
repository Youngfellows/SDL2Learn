Talk("客倌，看你一身打扮，不像是本地人，大老遠趕來，想必旅途一定勞累了．要不要在這住上一宿，讓你的體力，元氣恢復恢復．", 105, 0);
if AskRest() == true then goto  label0 end;
    exit();
::label0::
    if CheckEnoughMoney(40) == true then goto label1 end;
        Talk("走，走，走，沒錢就不要妨礙我做生意！", 105, 0);
        exit();
::label1::
        Talk("在此窮北寒苦絕地，居然能有間客棧真是惠我良多．", 0, 1);
        DarkScence();
        Rest();
        AddItemWithoutHint(174, -40);
        OldSetScencePosition(38, 18);
        SetTowards(3);
        LightScence();
exit();
