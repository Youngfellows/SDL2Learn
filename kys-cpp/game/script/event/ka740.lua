Talk("好吧，如果你能幫蘇普救出阿曼，地圖借你一看又何妨。", 0, 5);
Talk("這段話好像前幾天才在某個電影臺看到……", 146, 0);
Talk("參見大汗，大汗，我想跟你討個人．", 0, 5);
Talk("參見大汗，英明的大汗，胸襟有如海洋一樣開闊的大汗，我想跟你討個人．", 146, 0);
Talk("誰?", 0, 5);
Talk("好像是有這名女子，并且已經被我收到後宮了．", 146, 0);
DarkScence();
LightScence();
Talk("大汗後宮無數，這名叫阿曼的女子，是否可以割愛交給我．", 203, 1);
Talk("記住，出去闖蕩江湖一切都要小心，人心險惡啊!", 0, 5);
Talk("我後宮的確很多，而且開一次宴會，只能邀請十個女人，多出來也沒用，我可以把這女人讓給你，不過也要看阿曼的意思，來人啊!帶阿曼出來!", 203, 1);
Talk("阿曼!", 149, 4);
Talk("干，不是說好一切交給我，你來這做啥?讓事情更復雜．", 146, 0);
Talk("對不起，我偷偷跟你過來，看到阿曼忍不住出了聲．", 196, 0);
Talk("他就是當日脫逃的塔塔兒人，來人，快把他抓起來．", 203, 5);
if InTeam(49) == false then goto label0 end;
    Talk("等等，我想聽聽阿曼的決定是留或是去．", 49, 1);
::label0::
    Talk("蘇普 你走吧!我的身跟心都獻給了大汗，大汗是草原之鷹，英明的雄主，雖然你我曾經有婚約，這段婚約我希望作廢．", 0, 5);
    Talk("我．．．我不相信，阿曼阿曼!", 146, 0);
    Talk("傻孩子，沒錢又沒車怎麼跟鐵木真搶女人．", 0, 5);
    Talk("大汗，可否看在我的面子上，饒了蘇普一命<蘇普掛在這里，高昌地圖就沒希望拿到了>", 203, 1);
    Talk("蘇普本為阿曼未婚夫，雖然我有將阿曼還給蘇普之心，但是阿曼不肯我也沒辦法，念在蘇普也是個草原上的勇士，我饒他一命 ．", 0, 5);
    ModifyEvent(-2, -2, -2, 0, 1159, -1, -1, -2, -2, -2, -2, -2, -2);
    ModifyEvent(89, 0, 0, -2, -1, -1, -1, -1, -1, -1, -2, -2, -2);
    ModifyEvent(89, 3, -2, -2, 741, -1, -1, -2, -2, -2, -2, -2, -2);
exit();
