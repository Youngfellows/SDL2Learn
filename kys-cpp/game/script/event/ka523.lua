Talk("哇！這兒有那麼多乞丐，我身上的零錢可能不太夠．", 0, 1);
Talk("閣下別驚慌，我們群丐在這里聚聚，不會向你乞討的．", 93, 0);
Talk("一大群乞丐聚在這里，你們該不會是丐幫吧？", 0, 1);
Talk("正是．", 93, 0);
Talk("久聞丐幫乃天下第一大幫，人數之眾，為武林之最．小弟行走江湖，說什麼也得認識一下丐幫的英雄好漢．", 0, 1);
Talk("閣下好說．", 93, 0);
Talk("不知這位大哥是否可替我引見一下貴幫幫主．", 0, 1);
Talk("想見我們幫主，那也得是個英雄好漢才行．", 93, 0);
Talk("怎樣才算是個英雄好漢？", 0, 1);
Talk("你說呢．", 93, 0);
Talk("嗯．．．．．．．．．．．．．．．．．．．．久聞丐幫打狗陣威力無比，在下不才，想與各位切磋切磋．", 0, 1);
if TryBattle(82) == true then goto label0 end;
    ModifyEvent(-2, 0, -2, -2, 580, -1, -1, -2, -2, -2, -2, -2, -2);
    ModifyEvent(-2, 1, -2, -2, 580, -1, -1, -2, -2, -2, -2, -2, -2);
    ModifyEvent(-2, 5, -2, -2, 580, -1, -1, -2, -2, -2, -2, -2, -2);
    LightScence();
    Talk("閣下這樣的功夫，似乎不配見我家幫主．", 93, 0);
    exit();
::label0::
    ModifyEvent(-2, 0, 0, 0, -1, -1, -1, -1, -1, -1, -2, -2, -2);
    ModifyEvent(-2, 1, 0, 0, -1, -1, -1, -1, -1, -1, -2, -2, -2);
    ModifyEvent(-2, 5, 0, 0, -1, -1, -1, -1, -1, -1, -2, -2, -2);
    ModifyEvent(-2, 2, -2, -2, 524, -1, -1, -2, -2, -2, -2, -2, -2);
    ModifyEvent(-2, 3, -2, -2, 524, -1, -1, -2, -2, -2, -2, -2, -2);
    ModifyEvent(-2, 4, -2, -2, 524, -1, -1, -2, -2, -2, -2, -2, -2);
    ModifyEvent(-2, 6, -2, -2, 524, -1, -1, -2, -2, -2, -2, -2, -2);
    ModifyEvent(-2, 7, -2, -2, 524, -1, -1, -2, -2, -2, -2, -2, -2);
    ModifyEvent(-2, 8, -2, -2, 524, -1, -1, -2, -2, -2, -2, -2, -2);
    ModifyEvent(-2, 9, -2, -2, 524, -1, -1, -2, -2, -2, -2, -2, -2);
    ModifyEvent(-2, 10, -2, -2, 524, -1, -1, -2, -2, -2, -2, -2, -2);
    ModifyEvent(-2, 11, -2, -2, 524, -1, -1, -2, -2, -2, -2, -2, -2);
    ModifyEvent(-2, 12, -2, -2, 524, -1, -1, -2, -2, -2, -2, -2, -2);
    ModifyEvent(-2, 13, -2, -2, 524, -1, -1, -2, -2, -2, -2, -2, -2);
    ModifyEvent(-2, 15, -2, -2, 524, -1, -1, -2, -2, -2, -2, -2, -2);
    ModifyEvent(-2, 16, -2, -2, 524, -1, -1, -2, -2, -2, -2, -2, -2);
    ModifyEvent(-2, 17, -2, -2, 524, -1, -1, -2, -2, -2, -2, -2, -2);
    ModifyEvent(-2, 18, -2, -2, 524, -1, -1, -2, -2, -2, -2, -2, -2);
    ModifyEvent(-2, 19, -2, -2, 524, -1, -1, -2, -2, -2, -2, -2, -2);
    LightScence();
    Talk("閣下功夫不錯，竟破了我丐幫之打狗陣法．喬幫主就在里面，請進，我家幫主一定很高興認識你．", 93, 0);
    AddFame(2);
exit();
