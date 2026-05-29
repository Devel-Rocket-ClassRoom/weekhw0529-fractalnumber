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
