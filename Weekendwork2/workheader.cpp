#include <iostream>
#include <vector>
#include <numeric>
#include <string>
#include "workheader.h"


int Homework01_Run(int Year, int Month, int Day)
{
  
    int totalday = 0;
    int LeapYearcount_400 = 0;
    int LeapYearcount_100 = 0;
    int LeapYearcount_4 = 0;
    bool isLeapYear = false;

    std::string Week_counter = "기본값";

    if (((Year % 4 == 0) && (Year % 100 != 0)) || (Year % 400 == 0))
    {
        isLeapYear = true;
    }
    else
    {
        isLeapYear = false;
    }

    printf("1. 윤년을 반영하여 입력한 연월일의 요일 계산하기\n\n");
    if (Year > 0)
    {
        if (((Month == 1) && (Day >= 1) && (Day <= 31))
            || ((Month == 2) && (Day >= 1) && (Day <= 28)) && (isLeapYear == false)
            || ((Month == 2) && (Day >= 1) && (Day <= 29)) && (isLeapYear == true)
            || ((Month == 3) && (Day >= 1) && (Day <= 31))
            || ((Month == 4) && (Day >= 1) && (Day <= 30))
            || ((Month == 5) && (Day >= 1) && (Day <= 31))
            || ((Month == 6) && (Day >= 1) && (Day <= 30))
            || ((Month == 7) && (Day >= 1) && (Day <= 31))
            || ((Month == 8) && (Day >= 1) && (Day <= 31))
            || ((Month == 9) && (Day >= 1) && (Day <= 30))
            || ((Month == 10) && (Day >= 1) && (Day <= 31))
            || ((Month == 11) && (Day >= 1) && (Day <= 30))
            || ((Month == 12) && (Day >= 1) && (Day <= 31))
            )
        {

            // -- 윤년을 제외한 일수 계산 --

            totalday = Year * 365;

            // -- 월수에 따른 일수 계산 --

            if (Month == 2)
            {
                totalday += 31; // 1개월치
            }
            else if (Month == 3)
            {
                totalday += 59; // 2개월치
            }
            else if (Month == 4)
            {
                totalday += 90; // 3개월치
            }
            else if (Month == 5)
            {
                totalday += 120; // 4개월치
            }
            else if (Month == 6)
            {
                totalday += 151; // 5개월치
            }
            else if (Month == 7)
            {
                totalday += 181; // 6개월치
            }
            else if (Month == 8)
            {
                totalday += 212; // 7개월치
            }
            else if (Month == 9)
            {
                totalday += 243;  // 8개월치
            }
            else if (Month == 10)
            {
                totalday += 273;  // 9개월치
            }
            else if (Month == 11)
            {
                totalday += 304;  // 10개월치
            }
            else if (Month == 12)
            {
                totalday += 334;  // 11개월치
            }

            // -- 일수 더하기 --

            totalday += Day;


            // -- 윤년 계산해서 일수 더하기 --

            LeapYearcount_4 = Year / 4;
            LeapYearcount_100 = Year / 100;
            LeapYearcount_400 = Year / 400;

            // -- 최종 계산, 출력 프로세스 --

            totalday = totalday + (LeapYearcount_4 - LeapYearcount_100 + LeapYearcount_400);

            printf("총 일수는 %d 일 입니다.", totalday);
            printf("\n\n");

            if (totalday % 7 == 0)
            {
                Week_counter = "토요일";
            }
            else if (totalday % 7 == 1)
            {
                Week_counter = "일요일";
            }
            else if (totalday % 7 == 2)
            {
                Week_counter = "월요일";
            }
            else if (totalday % 7 == 3)
            {
                Week_counter = "화요일";
            }
            else if (totalday % 7 == 4)
            {
                Week_counter = "수요일";
            }
            else if (totalday % 7 == 5)
            {
                Week_counter = "목요일";
            }
            else if (totalday % 7 == 6)
            {
                Week_counter = "금요일";
            }

            printf("%d년 %d월 %d일은 [%s]입니다.", Year, Month, Day, Week_counter.c_str());

            printf("\n\n");
        }
        else
        {
            printf("연도 또는 월 또는 일에 잘못된 값이 입력되었습니다. 입력한 값을 확인해주세요.\n\n");
        }
    }
    else
    {
        printf("연도 또는 월 또는 일에 잘못된 값이 입력되었습니다. 입력한 값을 확인해주세요.\n\n");
    }
    return 0;

}

void Homework02_Run()
{
    // 제일 작은 순으로 1,2,3,4,5,6 을 합하면 21이 되므로 7칸 이상의 슬롯은 의미가 없음.

    std::string PlayerCards[6] = { "0","0" ,"0" ,"0" ,"0" ,"0" };
    std::string DealerCards[6] = { "0","0" ,"0" ,"0" ,"0" ,"0" };
    int PlayerNumArray[6] = { 0,0,0,0,0,0 };
    int DealerNumArray[6] = { 0,0,0,0,0,0 };
    int PlayerSum = 0;
    int DealerSum = 0;
    int PlayerReveal = 2;
    int DealerReveal = 2;
    bool blackjacked = false;
    bool gameend = false;

    std::string CardList[13] = { "A","2","3","4","5","6","7","8","9","10","J","Q","K" };

  

    int Round = 0;

    int dummyinput = 0;


    // 1. 메인 프롬프트

    printf("---------------------- 블랙잭 게임 ----------------------");
    printf("\n\n");
    printf("카드를 21이 나올때까지 뽑아보십시오. 내 카드의 합이 21과 가장 근접하면 승리합니다.");
    printf("\n");
    printf("단, 21을 넘기면 안됩니다.");


    // 2. 카드를 정해놓는 단계

    PlayerCards[0] = CardList[(rand() % 13)];
    PlayerCards[1] = CardList[(rand() % 13)];
    PlayerCards[2] = CardList[(rand() % 13)];
    PlayerCards[3] = CardList[(rand() % 13)];
    PlayerCards[4] = CardList[(rand() % 13)];
    PlayerCards[5] = CardList[(rand() % 13)];
    DealerCards[0] = CardList[(rand() % 13)];
    DealerCards[1] = CardList[(rand() % 13)];
    DealerCards[2] = CardList[(rand() % 13)];
    DealerCards[3] = CardList[(rand() % 13)];
    DealerCards[4] = CardList[(rand() % 13)];
    DealerCards[5] = CardList[(rand() % 13)];

    while (PlayerCards[0] == PlayerCards[1])
    {
        PlayerCards[1] = CardList[(rand() % 13)];
    }

    while ((PlayerCards[0] == PlayerCards[2]) ||
        (PlayerCards[1] == PlayerCards[2]))
    {
        PlayerCards[2] = CardList[(rand() % 13)];
    }

    while ((PlayerCards[0] == PlayerCards[3]) ||
        (PlayerCards[1] == PlayerCards[3]) ||
        (PlayerCards[2] == PlayerCards[3]))
    {
        PlayerCards[3] = CardList[(rand() % 13)];
    }

    while ((PlayerCards[0] == PlayerCards[4]) ||
        (PlayerCards[1] == PlayerCards[4]) ||
        (PlayerCards[2] == PlayerCards[4]) ||
        (PlayerCards[3] == PlayerCards[4]))
    {
        PlayerCards[4] = CardList[(rand() % 13)];
    }

    while ((PlayerCards[0] == PlayerCards[5]) ||
        (PlayerCards[1] == PlayerCards[5]) ||
        (PlayerCards[2] == PlayerCards[5]) ||
        (PlayerCards[3] == PlayerCards[5]) ||
        (PlayerCards[4] == PlayerCards[5]))
    {
        PlayerCards[5] = CardList[(rand() % 13)];
    }

    while ((PlayerCards[0] == DealerCards[0]) ||
        (PlayerCards[1] == DealerCards[0]) ||
        (PlayerCards[2] == DealerCards[0]) ||
        (PlayerCards[3] == DealerCards[0]) ||
        (PlayerCards[4] == DealerCards[0]) ||
        (PlayerCards[5] == DealerCards[0]))
    {
        DealerCards[0] = CardList[(rand() % 13)];
    }

    while ((PlayerCards[0] == DealerCards[1]) ||
        (PlayerCards[1] == DealerCards[1]) ||
        (PlayerCards[2] == DealerCards[1]) ||
        (PlayerCards[3] == DealerCards[1]) ||
        (PlayerCards[4] == DealerCards[1]) ||
        (PlayerCards[5] == DealerCards[1]) ||
        (DealerCards[0] == DealerCards[1]))
    {
        DealerCards[1] = CardList[(rand() % 13)];
    }

    while ((PlayerCards[0] == DealerCards[2]) ||
        (PlayerCards[1] == DealerCards[2]) ||
        (PlayerCards[2] == DealerCards[2]) ||
        (PlayerCards[3] == DealerCards[2]) ||
        (PlayerCards[4] == DealerCards[2]) ||
        (PlayerCards[5] == DealerCards[2]) ||
        (DealerCards[0] == DealerCards[2]) ||
        (DealerCards[1] == DealerCards[2]))
    {
        DealerCards[2] = CardList[(rand() % 13)];
    }

    while ((PlayerCards[0] == DealerCards[3]) ||
        (PlayerCards[1] == DealerCards[3]) ||
        (PlayerCards[2] == DealerCards[3]) ||
        (PlayerCards[3] == DealerCards[3]) ||
        (PlayerCards[4] == DealerCards[3]) ||
        (PlayerCards[5] == DealerCards[3]) ||
        (DealerCards[0] == DealerCards[3]) ||
        (DealerCards[1] == DealerCards[3]) ||
        (DealerCards[2] == DealerCards[3]))
    {
        DealerCards[3] = CardList[(rand() % 13)];
    }

    while ((PlayerCards[0] == DealerCards[4]) ||
        (PlayerCards[1] == DealerCards[4]) ||
        (PlayerCards[2] == DealerCards[4]) ||
        (PlayerCards[3] == DealerCards[4]) ||
        (PlayerCards[4] == DealerCards[4]) ||
        (PlayerCards[5] == DealerCards[4]) ||
        (DealerCards[0] == DealerCards[4]) ||
        (DealerCards[1] == DealerCards[4]) ||
        (DealerCards[2] == DealerCards[4]) ||
        (DealerCards[3] == DealerCards[4]))
    {
        DealerCards[4] = CardList[(rand() % 13)];
    }

    while ((PlayerCards[0] == DealerCards[5]) ||
        (PlayerCards[1] == DealerCards[5]) ||
        (PlayerCards[2] == DealerCards[5]) ||
        (PlayerCards[3] == DealerCards[5]) ||
        (PlayerCards[4] == DealerCards[5]) ||
        (PlayerCards[5] == DealerCards[5]) ||
        (DealerCards[0] == DealerCards[5]) ||
        (DealerCards[1] == DealerCards[5]) ||
        (DealerCards[2] == DealerCards[5]) ||
        (DealerCards[3] == DealerCards[5]) ||
        (DealerCards[4] == DealerCards[5]))
    {
        DealerCards[5] = CardList[(rand() % 13)];
    }

    // 3. 합치기용 배열

    for (int i = 0; i < sizeof(PlayerCards) / sizeof(PlayerCards[0]); i++)
    {
        if ((PlayerCards[i] == "J") || (PlayerCards[i] == "Q") || (PlayerCards[i] == "K"))
        {
            PlayerNumArray[i] = 10;
        }
        else if (PlayerCards[i] == "A")
        {
            PlayerNumArray[i] = 11;
        }
        else
        {
            PlayerNumArray[i] = stoi(PlayerCards[i]);
        }
    }

    for (int i = 0; i < Round + 2; i++)
    {
        PlayerSum += PlayerNumArray[i];
    }

    for (int i = 0; i < sizeof(DealerCards) / sizeof(DealerCards[0]); i++)
    {
        if ((DealerCards[i] == "J") || (DealerCards[i] == "Q") || (DealerCards[i] == "K"))
        {
            DealerNumArray[i] = 10;
        }
        else if (DealerCards[i] == "A")
        {
            DealerNumArray[i] = 11;
        }
        else
        {
            DealerNumArray[i] = stoi(DealerCards[i]);
        }
    }

    for (int i = 0; i < Round + 2; i++)
    {
        DealerSum += DealerNumArray[i];
    }


    // 4. 첫 카드, 에이스 계산

    printf("\n\n\n");
    printf("플레이어의 카드 2장과 딜러의 카드 1장을 공개합니다. 딜러의 남은 카드 1장은 최종 결과 전까지 비공개됩니다.");
    printf("\n\n");
    printf("플레이어 = [%s], [%s]   /   딜러 = [%s]", PlayerCards[0].c_str(), PlayerCards[1].c_str(), DealerCards[0].c_str());





    while (PlayerSum < 21 && DealerSum < 21 || gameend == false)
    {
               
        if ((PlayerSum < 21 && DealerSum < 21) && blackjacked == false && gameend == false)
        {
            printf("\n\n\n\n");
            printf("현재 가지고 있는 카드의 합이 21보다 작습니다. 카드를 받으시겠습니까?\n\n1 - 예 / 2 - 아니오");
            

            std::cin >> dummyinput;
            std::cin.clear();
            std::cin.ignore(10000, '\n');
        }

        if (dummyinput == 1)
        {
            printf("[%s] 카드를 하나  뽑았습니다.", PlayerCards[Round + 2].c_str());
            PlayerSum += PlayerNumArray[Round + 2];
            Round++;
            PlayerReveal++;
            if (DealerSum < 17)
            {
                printf("\n딜러는 현재 카드의 합이 17 미만이므로 카드를 계속 받습니다.");
                printf("\n딜러가 [%s] 카드를 하나 더 뽑았습니다.", DealerCards[Round + 2].c_str());
                DealerSum += DealerNumArray[Round + 2];
                Round++;
                DealerReveal++;
                

            }
            else
            {
                printf("\n딜러는 가진 카드 숫자의 합이 17 이상이므로 카드를 뽑지 않습니다.");
                goto calculate;
            }
            
            
        }
        else if (dummyinput == 2)
        {
            if (DealerSum < 17)
            {
                printf("\n딜러는 현재 카드의 합이 17 미만이므로 카드를 계속 받습니다.");
                printf("\n딜러가 [%s] 카드를 하나 더 뽑았습니다.", DealerCards[Round + 2].c_str());
                DealerSum += DealerNumArray[Round + 2];
                Round++;
                DealerReveal++;
                
               
            }
            else
            {
                printf("\n딜러는 가진 카드 숫자의 합이 17 이상이므로 카드를 뽑지 않습니다.");                
            }
        }
        else
        {
            printf("\n잘못된 입력. 1이나 2를 입력하세요.");            
        }

        calculate:
        if ((PlayerSum <= 21 && DealerSum <= 21) && (21 - PlayerSum) < (21 - DealerSum)) // 둘다 21 이하면서 내가 차이가 더 적을때
        {
            printf("\n플레이어가 21과 더 가깝습니다. 승리!!");
            printf("\n플레이어의 카드는 ");
            for (int i = 0; i < PlayerReveal; i++)
            {

                printf("[%s] ", PlayerCards[i].c_str());
            }
            printf("\n딜러의 카드는 ");
            for (int i = 0; i < DealerReveal; i++)
            {

                printf("[%s] ", DealerCards[i].c_str());
            }
            gameend = true;
            break;
            
        }
        else if ((PlayerSum <= 21 && DealerSum <= 21) && (21 - PlayerSum) > (21 - DealerSum)) // 둘다 21 이하면서 내가 차이가 더 클때
        {
            printf("\n딜러가 21과 더 가깝습니다. 패배!!");
            printf("\n플레이어의 카드는 ");
            for (int i = 0; i < PlayerReveal; i++)
            {

                printf("[%s] ", PlayerCards[i].c_str());
            }
            printf("\n딜러의 카드는 ");
            for (int i = 0; i < DealerReveal; i++)
            {

                printf("[%s] ", DealerCards[i].c_str());
            }
            gameend = true;
            break;
        }
        else if (PlayerSum > 21 && DealerSum <= 21) // 플레이어 버스트
        {
            printf("\n플레이어가 21을 넘었습니다. 패배!!");
            printf("\n플레이어의 카드는 ");
            for (int i = 0; i < PlayerReveal; i++)
            {

                printf("[%s] ", PlayerCards[i].c_str());
            }
            printf("\n딜러의 카드는 ");
            for (int i = 0; i < DealerReveal; i++)
            {

                printf("[%s] ", DealerCards[i].c_str());
            }
            gameend = true;
            break;
            
        }
        else if (PlayerSum <= 21 && DealerSum > 21) // 딜러 버스트
        {
            printf("\n딜러가 21을 넘었습니다. 승리!!");
            printf("\n플레이어의 카드는 ");
            for (int i = 0; i < PlayerReveal; i++)
            {

                printf("[%s] ", PlayerCards[i].c_str());
            }
            printf("\n딜러의 카드는 ");
            for (int i = 0; i < DealerReveal; i++)
            {

                printf("[%s] ", DealerCards[i].c_str());
            }
            gameend = true;
            break;
            
        }
        else if ((PlayerSum <= 21 && DealerSum <= 21) && (21 - PlayerSum) == (21 - DealerSum)) // 둘다 21 이하면서 동점일때
        {
            printf("\n동점입니다. 무승부.");
            printf("\n플레이어의 카드는 ");
            for (int i = 0; i < PlayerReveal; i++)
            {

                printf("[%s] ", PlayerCards[i].c_str());
            }
            printf("\n딜러의 카드는 ");
            for (int i = 0; i < DealerReveal; i++)
            {

                printf("[%s] ", DealerCards[i].c_str());
            }
            gameend = true;
            break;


        }
        
        if ((PlayerCards[0] == "A" || PlayerCards[1] == "A") && (PlayerNumArray[0] == 10 || PlayerNumArray[1] == 10))
        {
            printf("\n플레이어가 블랙잭에 도달했습니다. 승리했습니다.");
            blackjacked = true;
            gameend = true;
            break;
        }
        else if ((DealerCards[0] == "A" || DealerCards[1] == "A") && (DealerNumArray[0] == 10 || DealerNumArray[1] == 10))
        {
            printf("\n딜러의 2번째 카드는 [%s] 입니다.", DealerCards[1].c_str());
            printf("\n딜러가 블랙잭에 도달했습니다. 패배했습니다.");
            blackjacked = true;
            gameend = true;
            break;
        }
        
        /*
        printf("\n\n\n");
        printf("플레이어 카드의 합 = [%d]   /   딜러 카드의 합 = [%d]  /  디버깅용임.", PlayerSum, DealerSum);

        printf("\n\n\n\n");
        printf("플레이어가 가지고있는 카드 1.[%s] 2.[%s] 3.[%s] 4.[%s] 5.[%s] 6.[%s]",
            PlayerCards[0].c_str(), PlayerCards[1].c_str(), PlayerCards[2].c_str(), PlayerCards[3].c_str(), PlayerCards[4].c_str(), PlayerCards[5].c_str());
        printf("\n\n");
        printf("딜러가 가지고있는 카드 1.[%s] 2.[%s] 3.[%s] 4.[%s] 5.[%s] 6.[%s]",

            DealerCards[0].c_str(), DealerCards[1].c_str(), DealerCards[2].c_str(), DealerCards[3].c_str(), DealerCards[4].c_str(), DealerCards[5].c_str());

        */
    
    }
    
    

printf("\n\n\n");
}
