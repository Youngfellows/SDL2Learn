Talk("誰在亂叫，過去看看．", 0, 0);
Talk("是你，你怎麼跟這位老前輩一起在這．", 55, 0);
Talk("不是，我認識桃花島門人，想要上來桃花島找他<好爛的理由，總不能說要搶你的蓉兒>．", 0, 0);
Talk("不是，我認識桃花島門人，想要上來桃花島找他<好爛的理由，總不能說要搶你的蓉兒>．這位前輩是?", 64, 0);
Talk("別叫我前輩，叫我老頑童就好．", 0, 0);
Talk("老頑童?你就是老頑童周伯通，王重陽的師弟，你怎麼也在這．", 64, 0);
Talk("還不是那個該死黃老邪，為了九陰真經把我關在這，一關就是幾十年．", 0, 0);
Talk("幾十年在這個小地方，你沒被悶死．", 64, 0);
Talk("別說這個，義弟．剛才要你背的文章都背熟了沒?", 55, 0);
Talk("文章太長了，還沒．", 0, 0);
Talk("你居然跟老頑童結拜兄弟，老頑童就是老頑童．", 64, 0);
Talk("笨的跟頭豬一樣，對了，你來把這文章背熟．", 0, 0);
AddItem(94, 1);
Talk("才一瞬間，郭靖跟老頑童都不見了，快跟上去．", 55, 0);
SetRoleMagic(55, 0, 25, 700);
SetRoleMagic(55, 1, 21, 900);
AddMaxHP(55, 500);
AddMaxMP(55, 300);
AddSpeed(55, 10);
AddAttack(55, 20);
Talk("這書，不是九陰真經嗎?", 64, 0);
DarkScence();
LightScence();
AddMaxHP(0, 200);
AddMaxMP(0, 200);
AddSpeed(0, 10);
AddAttack(0, 20);
Talk("傻小子別羅唆，你快把里面文章背熟，我等不到這傻小子背完的時後．", 0, 0);
Talk("背好了．", 64, 0);
Talk("你的記憶力不錯，恩，頭頂有兩個旋，跟我一樣聰明．我很喜歡你，既然剛才我跟郭靖結拜過了，再結拜一次沒意思，那我就收你做我徒弟．", 0, 0);
Talk("老頑童武功我甚是佩服，當你徒弟我當然沒問題．", 60, 0);
Talk("藥兄，故友來訪，欲帶小侄跟藥兄閨女提親，請求一見．", 57, 0);
Talk("我已將桃花陣陣法關閉，歐陽兄近來談便是．", 55, 0);
Talk("怎麼辦，歐陽克帶他叔父來跟蓉兒提親了，我卻還被困在這．", 0, 0);
Talk("郭兄免緊張，剛才黃島主不是說了，他將桃花陣關了，我們尾隨進入就是．", 64, 0);
DarkScence();
ModifyEvent(-2, 8, 0, -2, -1, -1, -1, -1, -1, -1, -2, -2, -2);
ModifyEvent(-2, 9, 0, -2, -1, -1, -1, -1, -1, -1, -2, -2, -2);
ModifyEvent(-2, 10, 0, -2, -1, -1, 1168, -2, -2, -2, -2, -2, -2);
ModifyEvent(-2, 11, 0, -2, -1, -1, -1, 7992, 7992, 7992, -2, -2, -2);
ModifyEvent(-2, 12, 0, -2, -1, -1, -1, 7970, 7970, 7970, -2, -2, -2);
ModifyEvent(-2, 13, 0, -2, -1, -1, -1, 7972, 7972, 7972, -2, -2, -2);
ModifyEvent(-2, 17, 1, -2, -1, -1, -1, 8228, 8228, 8228, -2, -2, -2);
LightScence();
Talk("好玩，老頑童決定湊這個熱鬧．", 0, 0);
exit();
