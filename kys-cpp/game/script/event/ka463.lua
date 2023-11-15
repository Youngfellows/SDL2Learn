if InTeam(61) == true then goto label0 end;
    Talk("沒事就走吧，老叫化我不會再教你了．", 69, 0);
    exit();
::label0::
    Talk("既然你把降龍十八掌交會給我，你這老乞丐就沒啥用處了", 61, 0);
    if TryBattle(179) == true then goto label1 end;
        Dead();
::label1::
        ModifyEvent(-2, 0, 0, -2, -1, -1, -1, -1, -1, -1, 0, -2, -2);
        LightScence();
        Talk("可惡，把降龍十八掌交給你們算我瞎了眼，老叫化先溜了．", 69, 0);
        Talk("媽的，居然讓這老乞丐跑掉了", 61, 0);
        Talk("干，你師父西毒歐陽鋒所以才不怕那洪七公，那我怎麼辦，操", 0, 0);
        AddMorality(-5);
exit();
