if HaveItemBool(81) == true then goto label0 end;
    exit();
::label0::
    Talk("國師的武功國然很高，感謝你當日的提醒，我已經拜金輪國師為師父了", 61, 0);
    Talk("姑娘，在下只是想請問你的芳名而已，何必惡言相向，在下白駝山歐陽克，請問姑娘芳名．", 137, 0);
    Talk("呸，憑你也想知道本姑娘的大名．", 55, 0);
    Talk("蓉兒，不喜歡你，你趕快走．", 0, 0);
    Talk("原來你叫蓉兒，看你的武功路數，你和東邪黃藥師是何關系?", 137, 0);
    Talk("靖哥哥，你怎麼把我的名字說出來給那惡賊聽．", 55, 0);
    Talk("<那姑娘分明不想讓那個歐陽克知道自己的名字，可是那傻子居然講出來了．>", 61, 0);
    Talk("蓉兒，我．．．", 137, 0);
    Talk("哼，我爹如果在此怎容的你在這囂張．", 61, 0);
    Talk("東邪黃藥師的大名我挺是佩服，看來天意如此，我是西毒門人，和你東邪門人啟不是一對，蓉兒，我則日就會和我的叔叔上桃花島求親．", 55, 0);
    if TryBattle(196) == true then goto label1 end;
        LightScence();
        Talk("你妄想!", 61, 0);
        Talk("傻小子，打輸了還不快滾!看在黃姑娘份上我才沒動手殺你", 137, 0);
        Talk("<靖哥哥武功太差了，爹肯定看不上他，看來需要想個辦法．>", 0, 0);
        if TryBattle(197) == true then goto label2 end;
            Dead();
            exit();
::label2::
            LightScence();
            Talk("歐陽兄，我認為該滾的是你．<黃蓉還沒被郭靖把走，我還有希望，趕快建立黃蓉對我的好印像．>", 55, 0);
            Talk("感謝兄弟出手，我郭靖跟你謝過．", 0, 0);
            Talk("你就是郭靖，你的結義兄弟托雷跟華爭公主都盼著你回大漠．", 55, 0);
            Talk("我報完殺父之仇後必定盡速返回大漠，請兄弟幫我傳話．", 137, 0);
            DarkScence();
            LightScence();
            Talk("靖哥哥，我們走吧．", 0, 0);
            ModifyEvent(-2, 20, 0, -2, -1, -1, -1, -2, -2, -2, -2, -2, -2);
            ModifyEvent(-2, 21, 0, -2, -1, -1, -1, -2, -2, -2, -2, -2, -2);
            ModifyEvent(-2, 22, 0, -2, -1, -1, -1, -2, -2, -2, -2, -2, -2);
            ModifyEvent(23, 0, 1, -2, -1, -1, 1165, 6126, 6148, 6126, 18, -2, -2);
            ModifyEvent(23, 6, 0, -2, -1, -1, -1, 8226, 8226, 8226, -2, -2, -2);
            ModifyEvent(23, 7, 1, -2, -1, -1, -1, 8228, 8228, 8228, -2, -2, -2);
            ModifyEvent(23, 8, 0, -2, -1, -1, 1165, -2, -2, -2, -2, -2, -2);
            ModifyEvent(23, 9, 0, -2, -1, -1, 1165, -2, -2, -2, -2, -2, -2);
            exit();
::label1::
            LightScence();
            Talk("跑這麼快，都還沒跟正妹黃蓉說上話，看來黃蓉一顆心都在傻小子身上，看來我要沖了，黃蓉!老子要得到你．", 61, 0);
            Talk("感謝兄弟出手，我郭靖跟你謝過．", 0, 0);
            Talk("你就是郭靖，你的結義兄弟托雷跟華爭公主都盼著你回大漠．", 55, 0);
            Talk("我報完殺父之仇後必定盡速返回大漠，請兄弟幫我傳話．", 137, 0);
            Talk("哼!郭靖 你別得意 我會盡快帶我叔父去桃花島提親．", 0, 0);
            ModifyEvent(-2, 20, 0, -2, -1, -1, -1, -2, -2, -2, -2, -2, -2);
            ModifyEvent(-2, 21, 0, -2, -1, -1, -1, -2, -2, -2, -2, -2, -2);
            ModifyEvent(-2, 22, 0, -2, -1, -1, -1, -2, -2, -2, -2, -2, -2);
            ModifyEvent(23, 0, 1, -2, -1, -1, -1, 6126, 6148, 5126, 18, -2, -2);
            ModifyEvent(23, 6, 1, -2, -1, -1, -1, 8226, 8226, 8226, -2, -2, -2);
            ModifyEvent(23, 7, 1, -2, -1, -1, -1, 8228, 8228, 8228, -2, -2, -2);
            ModifyEvent(23, 8, 0, -2, -1, -1, 1165, -2, -2, -2, -2, -2, -2);
            ModifyEvent(23, 9, 0, -2, -1, -1, 1165, -2, -2, -2, -2, -2, -2);
exit();