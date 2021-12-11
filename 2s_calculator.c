#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#define PI 3.1415926


double tri () {

int z = 0;
double ang,x,y,i;
char si,sn,sa,mo;
int c,r;
char *fortune = "",*color ="";

    while(1){
        scanf("%c",&sa);
        if (sa == 's' || sa == 'c' || sa == 't'){
            break;
        }
    }
    scanf("%lf",&ang);
    //yの三角関数の種類の選択//
    if(sa == 's'){
        y = sin(ang*PI/180.0);
            printf("sin %.1lf(deg) = %.3lf\n",ang,y);
    }
    else if(sa == 'c'){
        y = cos(ang*PI/180.0);
            printf("cos %.1lf(deg) = %.3lf\n",ang,y);
    }
    else if(sa == 't'){
    if(89.9999 < ang && ang < 90.0001|| 269.9999 < ang && ang < 270.0001){
        i = ang;
        ang = 0;
        printf("error\nt");
        scanf("%lf",&ang);
    }
    y = tan(ang*PI/180.0);
        printf("tan %.1lf(deg) = %.3lf\n",ang,y);
        }
    else {
        printf("error");
        printf("%c", sa);
    }

return y;
}

int main(void) {

int z = 0;
double ang,x,y,i;
char si,sn,sa,mo;
int c,r;
char *fortune = "",*color ="";

    printf("電卓モードは'd'運勢占いは'k'\n");
    scanf("%c",&mo);

    //ここから四則演算//
    if (mo == 'd'){
        scanf ("%lf",&x);

        while (1) {
            z = 0;
            while(1){
                scanf("%c",&si);
                if (si == '+' || si == '-' || si == '*' || si == '/' || si == 'f' || si == 'h'){
                    break;
                }
            }
            switch (si) {
                case '+':
                    scanf ("%lf",&y);
                    x += y;
                    printf ("=%.1lf\n",x);
                    break;
                case '-':
                    scanf ("%lf",&y);
                    x -= y;
                    printf ("=%.1lf\n",x);
                    break;
                case '*':
                    scanf ("%lf",&y);
                    x *= y;
                    printf ("=%.1lf\n",x);
                    break;
                case '/':
                    scanf ("%lf",&y);
                    if (y == 0){
                        printf("ERROR!\n");
                        break;
                    }
                    x /= y;
                    printf ("=%.1lf\n",x);
                    break;
                case 'h':
                    printf ("fキー:三角関数\n");
                    printf ("aキー:元に戻る\n");
                    printf ("sinは's',cosは'c',tanは't'\n");
                    break;
                case 'f':
                //ここから三角関数//
                while(1){
                    while(1){
                        scanf("%c",&sn);
                        if (sn == '+' || sn == '-' || sn == '*' || sn == '/' || sn == 'a'){
                            break;
                        }
                    }
                    switch (sn) {
                        case '+':
                            y = tri();
                            x += y;
                            break;
                        case '-':
                            y = tri();
                            x -= y;
                            break;
                        case '*':
                            y = tri();
                            x *= y;
                            break;
                        case '/':
                            y = tri();
                            x /= y;
                            break;
                        case 'a':
                            z = 1;
                            break;
                        default:
                            break;
                    }
                    if (z != 1){
                    printf ("=%.1lf\n",x);
                    }
                    if(z == 1) {
                        break;
                    }
                }
                    break;
                default:
                    break;
                }
            }
    }
    else if (mo == 'k'){

        srand((unsigned)time(NULL));
        r = rand() %6;
        c = rand() %6;

        switch (r){
            case 0:
                fortune = "大吉";
                printf ("今日の運勢は%sです。良い一日を！\n",fortune);
                break;
            case 1:
                fortune = "吉";
                printf ("今日の運勢は%sです。いいことあるかも！\n",fortune);
                break;
            case 2:
                fortune = "中吉";
                printf ("今日の運勢は%sです。普通の一日になると思います\n",fortune);
                break;
            case 3:
                fortune = "小吉";
                printf ("今日の運勢は%sです。少しツイていないかもしれません\n",fortune);
                break;
            case 4:
                fortune = "末吉";
                printf ("今日の運勢は%sです。一日気を付けて過ごして下さい\n",fortune);
                break;
            case 5:
                fortune = "凶";
                printf ("今日の運勢は%sです。こんな日もあります、どうか気を落とさないで\n",fortune);
                switch(c){
                    case 0:
                        color = "赤";
                        printf ("凶を引いてしまったあなたのラッキーカラーは%sです、熱くなりましょう！\n",color);
                        break;
                    case 1:
                        color = "青";
                        printf ("凶を引いてしまったあなたのラッキーカラーは%sです、冷静になりましょう\n",color);
                        break;
                    case 2:
                        color = "黄";
                        printf ("凶を引いてしまったあなたのラッキーカラーは%sです、元気よく！\n",color);
                        break;
                    case 3:
                        color = "緑";
                        printf ("凶を引いてしまったあなたのラッキーカラーは%sです、穏やかに過ごしましょう\n",color);
                        break;
                    case 4:
                        color = "黒";
                        printf ("凶を引いてしまったあなたのラッキーカラーは%sです、オンオフ切り替えていきましょう\n",color);
                        break;
                    case 5:
                        color = "白";
                        printf ("凶を引いてしまったあなたのラッキーカラーは%sです、自分らしく過ごしましょう\n",color);
                        break;
                }
        return EXIT_SUCCESS;
        }
    }
    return 0;
}
