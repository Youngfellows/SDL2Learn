Talk("想領教我胡家刀法，那就來吧！", 1, 0);
if AskBattle() == true then goto label0 end;
    exit();
::label0::
    Talk("晚輩斗膽向前輩討教討教．", 0, 1);
    if TryBattle(0) == false then goto label1 end;
        LightScence();
        Talk("名聞天下的胡家刀法，亦不過爾爾，江湖上所傳，恐怕言過其實了．", 0, 1);
        Talk("住嘴，要不是我所得之刀譜不全，你那接得了我十招．", 1, 0);
        Talk("刀譜不全？你說你使的是不完整的胡家刀法．", 0, 1);
        Talk("是的．等我尋得所失之刀譜咱們倆再較量較量吧！", 1, 0);
        Talk("那胡大哥可知”雪山飛狐”一書之下落．", 0, 1);
        Talk("只因我名字倒過來念之音為飛狐，而且長年居住於東北雪地里，所以江湖上的人送給我一個外號”雪山飛狐”．此外號正好與人人都想爭奪的”金氏天書”其中一書名稱相同．也正因如此，在這幾年間引來了一些武林人士的登門拜訪．不過，我胡斐確實不知此書的下落．", 1, 0);
        Talk("那告辭了，他日若有機會，再向胡大哥請教．", 0, 1);
        Talk("等我尋得所失之刀譜，咱們倆再較量較量吧！", 1, 0);
        ModifyEvent(-2, -2, -2, -2, 3, -2, -2, -2, -2, -2, -2, -2, -2);
        ModifyEvent(-2, 1, -2, -2, -2, -2, 8, -2, -2, -2, -2, -2, -2);
        AddFame(1);
        exit();
::label1::
        LightScence();
        Talk("不掂掂自己的份量，就敢上我遼東胡家．", 1, 0);
        Talk("小弟實在有要找到書的原因并不是大哥所想的貪求武林秘笈的小人．技不如人，我也不再多說，他日再向胡大俠領教胡家刀法．", 0, 1);
        ModifyEvent(-2, -2, -2, -2, 4, -2, -2, -2, -2, -2, -2, -2, -2);
        ModifyEvent(-2, 1, -2, -2, -2, -2, 9, -2, -2, -2, -2, -2, -2);
exit();
