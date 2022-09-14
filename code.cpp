#include <conio.h>
#include <stdio.h>
#include <iomanip.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <graphics.h>
#include <fstream.h>
int n = 0;
int validname(char ss[50]) // this function is used to validate names
{
    int i;
    int x = 0;
    for (i = 0; ss[i] != 0; i++)
    {
        if (!isalpha(ss[i]))
        {
            x = 1;
            break;
        }
    }
    if (x == 1)
        return 1;
    return 0;
}

int validint(char ss[50]) // This function is used to validate strings
{
    int j;
    int z = 0;

    18

        for (j = 0; ss[j] != '\0'; j++)
    {
        if (!isdigit(ss[j]))
        {
            z = 1;
            break;
        }
    }
    if (z == 1)
        return 1;
    return 0;
}
struct dateofbirth
{
    int d;
    int m;
    int y;
};
class student
{
    int adno;
    char name[50];
    int sclass;
    char fname[50];
    char mname[50];
    int batch;
    dateofbirth dob;
    int marksp, marksc, phyp, chemp, marksm, csp, markscs, markse;
    float per;
    char grade;
    float tot;
    void calculate() // calculates the grade, total and percentage of a student of a class

        19

    {
        tot = marksp + marksc + phyp + chemp + marksm + csp + markscs + markse;
        per = (marksp + marksc + phyp + chemp + marksm + csp + markscs + markse) / 5.0;
        if (per >= 90)
            grade = 'A';
        else if (per >= 80)
            grade = 'B';
        else if (per >= 70)
            grade = 'C';
        else
            grade = 'F';
    }

public:
    void input();
    void display() // displays the details of an individual student of a class.
    {
        cout << "\n\t\t-----Details of a student-----";
        cout << "\n\t\tAdmission Number :" << adno;
        cout << "\n\t\tName :" << name;
        cout << "\n\t\tClass :" << sclass;
        cout << "\n\t\tFather's Name :" << fname;
        cout << "\n\t\tMother's Name :" << mname;
        cout << "\n\t\tBatch :" << batch;
        cout << "\n\t\tDate of birth :" << dob.d << "/" << dob.m << "/" << dob.y;
        cout << "\n\t\t -------------Marks-------------";
        cout << "\n\t\tPhysics theory :" << marksp;
        cout << "\n\t\tPhysics practical :" << phyp;
        cout << "\n\t\tChemistry theory :" << marksc;
        cout << "\n\t\tChemistry practical :" << chemp;
        cout << "\n\t\tMaths :" << marksm;
        cout << "\n\t\tEnglish :" << markse;
        cout << "\n\t\tComputer Science theory :" << markscs;
        cout << "\n\t\tComputer science practical :" << csp;
        cout << "\n\t\tTotal :" << tot;

        20 cout << "\n\t\tPercentage :" << setprecision(2) << per;
        cout << "\n\t\tGrade :" << grade;
    }
    void tab() // displays the details of all students of a class in tabular form.
    {
        cout << setw(6) << adno << setw(10) << name << setw(6) << marksp << setw(7) << phyp << setw(7) << marksc << set w(7) << chemp << setw(6) << marksm << setw(4) << markse << setw(6) << markscs << setw(6) << csp << setw(5) << setprecision(2) << per << " " << grade << endl;
    }
    int getadno() // returns the admission number of a student of a class
    {
        return adno;
    }
    int getclass() // returns the class of a student of a class.
    {
        return sclass;
    }
    void report() // displays the report card of a student
    {
        clrscr();
        cout << "\n\t---------------STUDENT REPORTCARD------------------";
        cout << "\n\tGrade:" << sclass << "|Year:" << batch << "|Adno:" << adno << "|Name:" << name;
        cout << "\n\tSUBJECT Max|Min|Marks Obtained";
        cout << "\n\t----------------------------------------------------- ";
        cout << "\n\tEnglish 100|33|" << markse;
        cout << "\n\tMaths 100|33|" << marksm;
        cout << "\n";
        cout << "\n\tPhysics Theory 70|23|" << marksp;
        cout << "\n\tPhysics Practical 30|10|" << phyp;
        cout << "\n\t------------------------------------------------------ ";
        cout << "\n\t Total 100|33|" << marksp + phyp;
        cout << "\n\t------------------------------------------------------ ";

        21 cout << "\n\tChemistry Theory 70|23|" << marksc;
        cout << "\n\tChemistry Practical 30|10" << chemp;
        cout << "\n\t------------------------------------------------------ ";
        cout << "\n\t Total 100|33|" << marksc + chemp;
        cout << "\n\t------------------------------------------------------ ";
        cout << "\n\tComputer Science Theory 70|33|" << markscs;
        cout << "\n\tCOmputer Science Practical 30|10|" << csp;
        cout << "\n\t------------------------------------------------------ ";
        cout << "\n\t Total 100|33|" << markscs + csp;
        cout << "\n\t------------------------------------------------------ ";
        int tot = marksp + phyp + marksc + chemp + markse + marksm + markscs + csp;
        cout << "\n\t------------------------------------------------------ ";
        cout << "\n\t GRAND TOTAL:" << tot << " Percentage:" << per << " Grade:" << grade;
        cout << "\n\t------------------------------------------------------ ";
    }
} st;
void student::input() // takes all values of a student for a report card.
{
    int w = 0;
    char ss[50];
l1:
    cout << "\n\t\tEnter admission number :";
    gets(ss);
    w = validint(ss);
    if (w == 1)
    {
        cout << "\n\t\t\t\tERROR";
        goto l1;
    }
    adno = atoi(ss);

l2:
    cout << "\n\t\tEnter name :";
    gets(ss);
    w = validname(ss);
    if (w == 1)
    {
        cout << "\n\t\t\t\tERROR";
        goto l2;
    }
    strcpy(name, ss);
l3:

    22 cout << "\n\t\tEnter Class(enter digits) :";
    gets(ss);
    w = validint(ss);
    if (w == 1)
    {
        cout << "\n\t\t\t\tERROR";
        goto l3;
    }
    sclass = atoi(ss);
l4:
    cout << "\n\t\tEnter Father's Name :";
    gets(ss);
    w = validname(ss);
    if (w == 1)
    {
        cout << "\n\t\t\t\tERROR";
        goto l4;
    }
    strcpy(fname, ss);
l5:
    cout << "\n\t\tEnter Mother's Name :";
    gets(ss);
    w = validname(ss);
    if (w == 1)
    {
        cout << "\n\t\t\t\tERROR";
        goto l5;
    }
    strcpy(mname, ss);

l6:
    cout << "\n\t\tEnter Year(Batch) :";
    gets(ss);
    w = validint(ss);
    if (w == 1)
    {
        cout << "\n\t\t\t\t\tERROR";
        goto l6;
    }
    batch = atoi(ss);
    if (batch < 2000 || batch > 2050)
    {
        cout << "\n\t\t\t\tWRONG BATCH ENTERED";
        goto l6;
    }
l7:
    cout << "\n\t\tDate of Birth:";
    cout << "\n\t\tEnter day :";
    gets(ss);
    w = validint(ss);
    if (w == 1)
    {
        cout << "\n\t\t\t\tERROR";
        goto l7;
    }
    dob.d = atoi(ss);
    cout << "\n\t\tEnter month :";
    gets(ss);
    w = validint(ss);
    if (w == 1)
    {
        cout << "\n\t\t\t\tERROR";
        goto l7;
    }
    dob.m = atoi(ss);
    cout << "\n\t\tEnter year :";
    gets(ss);

    23

        w = validint(ss);
    if (w == 1)
    {
        cout << "\n\t\t\t\tERROR";
        goto l7;
    }
    dob.y = atoi(ss);
    if (dob.y < 2000 || dob.d < 0 || dob.d > 31 || dob.m < 0 || dob.m > 12)
    {
        cout << "\n\t\t\tDATE INVALID";
        goto l7;
    }
    else
    {
        if (dob.m == 2 && (dob.d > 28 || dob.d < 0))
        {
            cout << "\n\t\t\tDATE INVALID";
            goto l7;
        }

        else if (dob.m == 1 || dob.m == 3 || dob.m == 5 || dob.m == 7 || dob.m == 8 || dob.m == 10 || dob.m == 12)
        {
            if (dob.d > 31 || dob.d < 0)
            {
                cout << "\n\t\t\tDATE INVALID";
                goto l7;
            }
        }
        else if (dob.m == 4 || dob.m == 6 || dob.m == 9 || dob.m == 11)
        {
            if (dob.d > 30)
            {
                cout << "\n\t\t\tDATE INVALID";
                goto l7;
            }
        }
    }

    cout << "\n\n\t\tEnter marks\n";
a1:
    cout << "\n\t\tphysics theory(70) :";
    gets(ss);
    w = validint(ss);
    if (w == 1)
    {
        cout << "\n\t\t\t\tERROR";
        goto a1;
    }
    marksp = atoi(ss);
    if (marksp > 70 || marksp < 0)

        24
        {
            cout << "\n\t\t\tWRONG MARKS ENTERED";
            goto a1;
        }
a2:
    cout << "\n\t\tphysics practical(30) :";
    gets(ss);
    w = validint(ss);
    if (w == 1)
    {
        cout << "\n\t\t\t\tERROR";
        goto a2;
    }
    phyp = atoi(ss);
    if (phyp > 30 || phyp < 0)
    {
        cout << "\n\t\t\tWRONG MARKS ENTERED";
        goto a2;
    }
a3:
    cout << "\n\t\tchemistry theory(70) :";
    gets(ss);
    w = validint(ss);
    if (w == 1)
    {
        cout << "\n\t\t\t\tERROR";
        goto a3;
    }
    marksc = atoi(ss);
    if (marksc > 70 || marksc < 0)
    {
        cout << "\n\t\t\tWRONG MARKS ENTERED";
        goto a3;
    }
a4:
    cout << "\n\t\tchemistry practical(30) :";
    gets(ss);
    w = validint(ss);
    if (w == 1)
    {
        cout << "\n\t\t\t\t\tERROR";
        goto a4;
    }
    chemp = atoi(ss);
    if (chemp > 30 || chemp < 0)
    {
        cout << "\n\t\t\t\tWRONG MARKS ENTERED";
        goto a4;
    }
a5:
    cout << "\n\t\tmaths(100) :";
    gets(ss);
    w = validint(ss);
    if (w == 1)
    {
        cout << "\n\t\t\t\tERROR";
        goto a5;
    }
    marksm = atoi(ss);
    if (marksm > 100 || marksm < 0)
    {
        cout << "\n\t\t\tWRONG MARKS ENTERED";
        goto a5;
    }

    25

        a6 : cout
             << "\n\t\tenglish(100) :";
    gets(ss);
    w = validint(ss);
    if (w == 1)
    {
        cout << "\n\t\t\t\tERROR";
        goto a6;
    }
    markse = atoi(ss);
    if (markse > 100 || markse < 0)
    {
        cout << "\n\t\t\tWRONG MARKS ENTERED";
        goto a6;
    }
a7:
    cout << "\n\t\tcomputer theory(70) : ";
    gets(ss);
    w = validint(ss);
    if (w == 1)
    {
        cout << "\n\t\t\t\tERROR";
        goto a7;
    }
    markscs = atoi(ss);
    if (markscs > 70 || markscs < 0)
    {
        cout << "\n\t\t\tWRONG MARKS ENTERED";
        goto a7;
    }
a8:
    cout << "\n\t\tcomputer practical(30) : ";
    gets(ss);
    w = validint(ss);
    if (w == 1)
    {
        cout << "\n\t\t\t\tERROR";
        goto a8;
    }
    csp = atoi(ss);
    if (csp > 30 || csp < 0)
    {
        cout << "\n\t\t\tWRONG MARKS ENTERED";
        goto a8;
    }
    calculate();
}
void main()
{
    clrscr();
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "C:\\TC\\BGI\\");
    settextstyle(1, 0, 4);

    26

        setbkcolor(MAGENTA);
    setcolor(WHITE);
    ofstream file8("report.dat", ios::binary | ios::out);
    if (!file8)
    {
        cout << "\n\t\tERROR";
        getch();
        exit(1);
    }
    file8.close();
    getch();
    outtextxy(120, 210, "STUDENT REPORT CARD");
    getch();
L1:
    clrscr();
    textmode(3);
    setbkcolor(BLUE);
    char ch[50];

    cout << "\n\n\n\n\n\t\t----------REPORTCARD GENERATION----------\n";
    cout << "\n\t\t1.Create a student record";
    cout << "\n\t\t2.Display a student record";
    cout << "\n\t\t3.Display student details of a class";
    cout << "\n\t\t4.Modify a student record";
    cout << "\n\t\t5.Delete a student record";
    cout << "\n\t\t6.Display reportcard of a student";
    cout << "\n\t\t7.Exit";
b1:
    cout << "\n\n\t\tEnter choice :";
    gets(ch);
    int w = validint(ch);
    if (w == 1)
    {
        cout << setw(20) << "\n\t\t\tERROR";
        goto b1;
    }
    int c = atoi(ch);
    switch (c)
    {
    case 1:
        clrscr();
        char ch4;
        ofstream f1("report.dat", ios::binary | ios::app);
        if (!f1)
        {
            cout << "error";
            exit(1);
        }

        27

            cout
            << "\n\t\t----------STUDENT REPORTCARD GENERATION---------";

        st.input();
        n++;
        f1.write((char *)&st, sizeof(st));
        cout << "\n\t\t\tSTUDENT RECORD SUCCESSFULLY ADDED";

        f1.close();
        getch();
        goto L1;
    case 2: // display details of a student
        clrscr();
        char ss[50];
        if (n != 0)
        {
            cout << "\n\t\t----------STUDENT REPORTCARD GENERATION----------\n";
            int adno;
        L2:
            ifstream f2("report.dat", ios::binary);
            if (!f2)
            {
                cout << "Error";
                exit(1);
            }
            cout << "\n\t\tEnter admission number :";
            gets(ss);
            int w1 = validint(ss);
            if (w1 == 1)
            {
                cout << "\n\t\tINVALID INPUT";
                goto L2;
            }
            adno = atoi(ss);
            int f7 = 0;
            while (!f2.eof())
            {
                f2.read((char *)&st, sizeof(st));
                if (f2.eof())
                    break;
                if (adno == st.getadno())
                {
                    st.display();
                    getch();
                    f7++;
                }
            }

            28

                if (f7 == 0)
            {
                cout << "\n\t\t\tADMISSION NO. NOT FOUND";
                getch();
            }
        }
        else
        {
            gotoxy(25, 10);
            cout << "STUDENT DETAILS NOT ENTERED";
            getch();
        }
        goto L1;
    case 3: // display student details of a class
        clrscr();
        char sc[50];
        ifstream f3("report.dat", ios::binary);
        if (!f3)
        {
            cout << "Error";
            exit(1);
        }
        if (n != 0)
        {
            cout << "\n\t\t----------STUDENT REPORTCARD GENERATION----------\n";
            int clas;
        L3:
            cout << "\n\t\tEnter the class to be displayed :";
            gets(sc);
            cout << "\n";
            int w2 = validint(sc);
            if (w2 == 1)
            {
                cout << "\n\t\t\t\t ERROR";
                goto L3;
            }
            clas = atoi(sc);
            int f = 0;
            while (!f3.eof())
            {
                f3.read((char *)&st, sizeof(st));
                if (f3.eof())
                    break;
                if (clas == st.getclass())
                {
                    ++f;
                    if (f == 1)
                    {
                        cout << setw(6) << "Ad.No" << setw(10) << "Name" << setw(6) << "Phy_T" << setw(7) << "Phys_P" << setw(7) < < "Chem_T" << setw(7) << "Chem_P" << setw(6) << "Maths" << setw(4) << "Eng" << setw(6) << "Com_T" << set w(6) << "Com_P" << setw(5) << "Per%"
                                                                                                                                              << " "
                                                                                                                                              << "Grade";
                        cout << "\n--------------------------------------------------------------------------------\n";
                    }
                    st.tab();
                    getch();
                }
            }
            if (f == 0)
            {
                cout << "\n\t\t\t NO STUDENT FOUND";
                getch();

                29
            }
        }
        else
        {
            gotoxy(25, 10);
            cout << "STUDENT DETAILS NOT ENTERED";
            getch();
        }

        goto L1;
    case 4: // to modify student detail
        fstream f4("report.dat", ios::binary | ios::in | ios::out);
        clrscr();
        if (!f4)
        {
            cout << "Error";
            exit(1);
        }
        char sp[50];
        if (n != 0)
            cout << "\n\t\t----------STUDENT REPORTCARD GENERATION----------\n";
        if (n != 0)
        {
        L4:
            cout << "\n\t\tEnter student admission no to be modified :";
            int f1 = 0;
            gets(sp);
            int w3 = validint(sp);
            if (w3 == 1)
            {
                cout << "\n\t\t\t\tERROR";
                goto L4;
            }
            int adno = atoi(sp);
            while (!f4.eof())
            {
                int p = f4.tellg();
                f4.read((char *)&st, sizeof(st));
                if (f4.eof())
                    break;
                if (adno == st.getadno())
                {
                    ++f1;
                    f4.seekp(p);
                    cout << "\n\n\t\t Enter data to be modified :";
                    st.input();
                    f4.write((char *)&st, sizeof(st));
                    cout << "\n\t\t\t\tDATA UPDATED";
                    getch();
                }
            }
            f4.close();

            30

                if (f1 == 0)
            {
                cout << "\n\t\t\t\tSTUDENT NOT FOUND";
                getch();
            }
        }
        else
        {
            gotoxy(25, 10);
            cout << "STUDENT
                DETAILS NOT ENTERED ";getch();
        }
        goto L1;
    case 5: // deletion of record
        clrscr();
        char sl[50];
        if (n != 0)
        {
            cout << "\n\t\t-----STUDENT REPORTCARD GENERATION------";
            ifstream t2("report.dat", ios::binary);
            ofstream t3("tempo.dat", ios::binary);
            if (!t2)
            {
                cout << "error";
                exit(0);
            }
            if (!t3)
            {
                cout << "error";
                exit(0);
            }
        L52:
            cout << "\n\t\tEnter admission number :";
            gets(sl);
            int w0 = validint(sl);
            if (w0 == 1)
            {
                cout << "\n\t\tINVALID INPUT";
                goto L52;
            }
            int adno = atoi(sl);
            int f = 0;
            while (!t2.eof())
            {
                t2.read((char *)&st, sizeof(st));
                if (t2.eof())
                    break;
                if (st.getadno() != adno)
                {
                    t3.write((char *)&st, sizeof(st));
                }
                else
                    f++;
            }
            t2.close();
            t3.close();
            remove("report.dat");
            rename("tempo.dat", "report.dat");

            31

                if (f == 0)
            {
                cout << "\n\t\t\t\tRECORD NOT FOUND";
                getch();
            }
            else
            {
                cout << "\n\t\t\tRECORD IS DELETED";
                getch();
            }
        }
        else
        {
            gotoxy(25, 10);
            cout << "STUDENT DETAILS NOT ENTERED";
            getch();
        }
        goto L1;
    case 6: // display reportcard of a student
        clrscr();
        char sd[50];
        if (n != 0)
        {
            cout << "\n\t\t----------STUDENT REPORTCARD GENERATION----------\n";
        L5:
            cout << "\n\t\tEnter admission number :";
            gets(sd);
            int w8 = validint(sd);
            int f = 0;
            if (w8 == 1)
            {
                cout << "\n\t\t\t\tERROR";
                goto L5;
            }
            int adno = atoi(sd);
            ifstream t1("report.dat", ios::binary);
            if (!t1)
            {
                cout << "error";
                exit(0);
            }
            while (!t1.eof())
            {
                t1.read((char *)&st, sizeof(st));
                if (t1.eof())
                    break;
                if (adno == st.getadno())
                {
                    ++f;
                    st.report();
                    getch();
                }
            }
            t1.close();
            if (f == 0)
            {
                cout << "\n\t\t\t\tRECORD NOT FOUND";
                getch();
            }
        }

        32

            else
        {
            gotoxy(25, 10);
            cout << "STUDENT DETAILS NOT ENTERED";
            getch();
        }
        goto L1;
    case 7: /* ofstream file8("report.dat", ios::binary|ios::out) ;
     if(!file8){cout<<"\n\t\tERROR";getch();exit(1);}
     file8.close(); n=0;*/
        exit(0);
        goto L1;
    default:
        cout << "\n\t\t\tWRONG INPUT";
        getch();
        goto L1;
    }
    // goto L1;
}