#include <cstdio>
#include <cstring>

using namespace std;

struct Student {
private:
    int ID;
    int score;
    char name[20];
public:
    Student (const int IDnumber, char *Name_input) {
        ID = IDnumber;
        for (int i = 0;; i++)
        {
            name[i] = Name_input[i];
            if ('\0' == Name_input[i])
                break;
        }
        score = -1;
    }

    Student() {
        ID = -1;
        score = -1;
    }

    void record(const int score_input) {
        score = score_input;
    }

    int Get_ID() {
        return ID;
    }

    int Get_score() {
        return score;
    }

    char* Get_name() {
        return name;
    }
};
const int Max_student = 10000;
struct Studentlist {
private:
    Student student[Max_student];
    int pre[Max_student], next[Max_student];
    int total;
    int head, tail;
public:
    Studentlist() {
        total = 0;
        head = 0;
        tail = 0;
        memset(pre, 0, sizeof(pre));
        memset(next, 0, sizeof(next));
    }
    bool full() {
        return Max_student == tail;
    }
    bool empty() {
        return 0 == total;
    }
    void join(const Student studentA) {
        if (full())
        {
            printf("Error!The studentlist is full.");
            return ;
        }
        int tmp = tail;
        tail++;
        total++;
        student[tail] = studentA;
        pre[tail] = tmp;
        next[tmp] = tail;
        next[tail] = 0;
        tail = total;
    }

    int find(const int ID_studentA) {
        int aim;
        for (aim = next[head]; aim; aim = next[aim])
        {
            if (ID_studentA == student[aim].Get_ID())
            {
                break;
            }
        }
        if (ID_studentA != student[aim].Get_ID())
        {
            printf("Error!There isn't such sutdent in the class.\n");
            return -1;
        }
        return aim;
    }

    void leave(const int ID_studentA) {
        if (empty())
        {
            printf("Error!The studentlist is empty.\n");
            return ;
        }
        int number = find(ID_studentA);
        if (-1 == number)
            return;
        if (number == tail)
        {
            tail = pre[tail];
        }
        total--;
        next[pre[number]] = next[number];
        pre[next[number]] = pre[number];
        next[number] = -1;
        pre[number] = -1;
    }

    void record(const int ID_studentA, const int score_input) {
        int number = find(ID_studentA);
        if (-1 == number)
            return;
        student[number].record(score_input);
        return;
    }

    void Showlist()
    {
        int now = next[0];
        printf("There are %d students in the class.\n", total);
        for (; now; now = next[now])
        {
            printf("%d  ID=%d  Name=%s score=%d\n", now, student[now].Get_ID(), student[now].Get_name(), student[now].Get_score());
        }
        puts("");
    }
} course;
int main() {
    for (;;)
    {
        char s[100];
        gets(s);
        switch (s[0]) {
        case 'S':
        {
            course.Showlist();
            break;
        }
        case 'J':
        {
            int ID_input;
            char Name_input[100];
            scanf("%d%s", &ID_input, Name_input);
            printf("%d %s\n", ID_input, Name_input);
            course.join(Student(ID_input, Name_input));
            break;
        }
        case 'L':
        {
            int ID_input;
            scanf("%d", &ID_input);
            course.leave(ID_input);
            break;
        }
        case 'R':
        {
            int ID_input, score_input;
            for (;;) {
                scanf("%d%d", &ID_input, &score_input);
                course.record(ID_input, score_input);
                printf("continue? <Y/N>\n");
                char ch = ' ';
                for (; ('Y' != ch) && ('N' != ch); ch = getchar());
                if ('N' == ch)
                    break;
            }
            break;
        }
        case 'E':
        {
            return 0;
        }

        }
    }
    return 0;
}