Talk("哇呀！……", 64, 0);
Talk("好像是老頑童的聲音？", 0, 1);
Talk("趙志敬，你敢欺師滅祖，聯合金輪法王害我。", 64, 0);
Talk("師叔祖，我也是迫不得已。你不要怪我。", 95, 1);
Talk("師父，我來幫你！", 0, 0);
if TryBattle(65) == true then goto label0 end;
    Dead();
    exit();
::label0::
    ModifyEvent(-2, 36, 0, 0, -1, -1, -1, -1, -1, -1, -2, -2, -2);
    ModifyEvent(-2, 37, 0, 0, -1, -1, -1, -1, -1, -1, -2, -2, -2);
    ModifyEvent(-2, 38, 0, 0, -1, -1, -1, -1, -1, -1, -2, -2, -2);
    ModifyEvent(-2, 39, 0, 0, -1, -1, -1, -1, -1, -1, -2, -2, -2);
    ModifyEvent(-2, 40, 0, 0, -1, -1, -1, -1, -1, -1, -2, -2, -2);
    ModifyEvent(-2, 41, 0, 0, -1, -1, -1, -1, -1, -1, -2, -2, -2);
    LightScence();
    Talk("謝謝你啦，徒弟！周伯通我天不怕地不怕，可對這些蜘蛛、毒蛇就一點辦法也沒有了。", 64, 0);
    Talk("不用客氣。", 0, 1);
    Talk("我的命對你是不要緊，對我老頑童可要緊得很。總之，我欠你一個人情。", 64, 0);
    Talk("真的不用了，你不是我師父嗎?救你是應該的。", 0, 1);
    Talk("這樣吧，徒弟，我教你一個好玩的游戲．", 64, 0);
    Talk("什麼游戲？", 0, 1);
    Talk("我老頑童獨創的”左右互搏之術”．這是當年我被黃老邪關在桃花島十五年間，無聊時所創出的武功．要知在這十五年中，我苦無對手拆招，只好左手和右手打架．", 64, 0);
    Talk("左手怎能和右手打架？", 0, 1);
    Talk("我假裝右手是黃老邪，左手是老頑童．右手一掌打去，左手拆開之後還了一拳，就這樣打了起來．", 64, 0);
    Talk("這功夫很難學吧？", 0, 1);
    Talk("說難是難到極處，說容易也容易之至．有的人一輩子都學不會，有的人只需幾天便會了．好像越是聰明，越是不成，看看你是否有這機緣看著了．．．第一課”左手畫方，右手畫圓”．．．．", 64, 0);
    DarkScence();
    LightScence();
    Talk("功夫是教你了，接下來就看看你有沒有這造化了．", 64, 0);
    AddItem(91, 1);
    ModifyEvent(-2, -2, -2, -2, 413, -1, -1, -2, -2, -2, -2, -2, -2);
    AddFame(1);
exit();