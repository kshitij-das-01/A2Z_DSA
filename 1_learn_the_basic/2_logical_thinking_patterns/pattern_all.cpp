#include <iostream>

void pattern1(int n)
{
    for (int i = 0; i < 4; i++)
    {
        std::cout << "****\n";
    }
    
}
void pattern2(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            std::cout << "* ";
        }
        std::cout << "\n";
    }
}
void pattern3(int n)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            std::cout << j << " ";
        }
        std::cout << "\n";
    }
}
void pattern4(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            std::cout << i << " ";
        }
        std::cout << "\n";
    }
}
void pattern5(int n)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < (n - i + 1); j++)
        {
            std::cout << "* ";
        }
        std::cout << "\n";
    }
}
void pattern6(int n) 
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 1; j <= n-i; j++)
        {
            std::cout << j << " ";
        }
        std::cout << "\n";
    }
}
void pattern7(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int sp1 = 0; sp1 < n-i-1; sp1++)
        {
            std::cout << " ";
        }
        for (int j = 0; j < 2*i + 1; j++)
        {
            std::cout << "*";
        }
        for (int sp2 = 0; sp2 < n-i-1; sp2++)
        {
            std::cout << " ";
        }
        std::cout << '\n';
    }
}
void pattern8(int n) 
{
    for (int i = 0; i < n; i++)
    {
        for (int sp = 0; sp < i; sp++)
        {
            std::cout << " ";
        }
        for (int j = 0; j < 2*(n-i) - 1; j++)
        {
            std::cout << "*";
        }
        for (int sp = 0; sp < i; sp++)
        {
            std::cout << " ";
        }
        std::cout << '\n';
    }
}
void pattern10(int n)
{
    for (int i = 1; i <= 2*n - 1; i++)
    {
        int stars = i;

        if (i > n)
            stars = 2*n - i;

        for (int j = 1; j <= stars; j++)
        {
            std::cout << '*';
        }
        std::cout << '\n';
    }
}
void pattern11(int n)
{
    int start = 1;
    for (int i = 0; i < n; i++)
    {
        if (i % 2 == 0)
            start = 1;
        else 
            start = 0;

        for (int j = 0; j <= i; j++)
        {
            std::cout << start << ' ';
            start = 1 - start;
        }
        std::cout << '\n';
    }
}
void pattern12_1(int n)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
            std::cout << j;
        
        for (int sp = 1; sp < 2*(n-i)+1; sp++)
            std::cout << ' ';

        for (int j = i; j >= 1; j--)
            std::cout << j;
        
        std::cout << '\n';
    }
    std::cout << '\n';
}
void pattern12_2(int n)
{
    int space = 2* (n-1);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
            std::cout << j;

        for (int j = 1; j <= space; j++)
            std::cout << ' ';
        
        for (int j = i; j >= 1; j--)
            std::cout << j;
        
        std::cout << '\n';
        space -= 2;
    }
}
void pattern13(int n)
{
    int num = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            std::cout << num << ' ';
            num++;
        }
        std::cout << '\n';
    }
}
void pattern14(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (char ch = 'A'; ch <= 'A' + i; ch++)
        {
            std::cout << ch << ' ';
        }
        std::cout << '\n';
    }
}
void pattern15(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (char ch = 'A'; ch < 'A' + (n - i); ch++)
        {
            std::cout << ch << ' ';
        }
        std::cout << '\n';
    }
}
void pattern16(int n)
{
    for (int i = 0; i < n; i++)
    {
        char ch = 'A' + i;

        for (int j = 0; j <= i; j++)
            std::cout << ch << ' ';

        std::cout << '\n';
    }
}
void pattern17(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n-i-1; j++)
        {
            std::cout << " ";
        }

        char ch = 'A';
        int breakpoint = (2*i + 1) / 2;
        for (int j = 0; j < 2*i + 1; j++)
        {
            std::cout << ch;

            if (j < breakpoint) ch++;
            else ch--;
        }

        for (int j = 0; j < n-i-1; j++)
        {
            std::cout << " ";
        }
        std::cout << '\n';
    }
}
void pattern18(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (char ch = 'E' - i; ch <= 'E'; ch++)
        {
            std::cout << ch << ' ';
        }
        std::cout << '\n';
    }
}
void pattern19_1(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n-i; j++)
            std::cout << "*";
        
        for (int sp = 0; sp < 2*i; sp++)
        {
            std::cout << ' ';
        }

        for (int j = 0; j < n-i; j++)
            std::cout << "*";
        
        std::cout << '\n';
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= i; j++)
            std::cout << "*";
        
        for (int sp = 0; sp < 2*(n-i-1); sp++)
            std::cout << " ";

        for (int j = 0; j <= i; j++)
            std::cout << "*";
        
        std::cout << '\n';
    }
}
void pattern19_2(int n)
{
    int space = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < (n-i); j++)
            std::cout << "*";

        for (int sp = 0; sp < space; sp++)
            std::cout << " ";

        for (int j = 0; j < (n-i); j++)
            std::cout << "*";

        space += 2;
        std::cout << '\n';
    }

    space = 2*n - 2;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= i; j++)
            std::cout << "*";

        for (int sp = 0; sp < space; sp++)
            std::cout << " ";

        for (int j = 0; j <= i; j++)
            std::cout << "*";

        space -= 2;
        std::cout << '\n';
    }
}
void pattern20(int n)
{
    int spaces = 2*n - 2;
    for (int i = 1; i <= 2*n-1; i++)
    {
        int stars = i;
        if (i > n) stars = 2*n - i;
        //stars
        for (int j = 1; j <= stars; j++)
            std::cout << "*";
        
        for (int j = 0; j < spaces; j++)
            std::cout << " ";

        for (int j = 1; j <= stars; j++)
            std::cout << "*";
        
        std::cout << '\n';
        if (i < n) spaces -= 2;
        else spaces += 2;
    }
}
void pattern21(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == 0 || j == 0 || i == n-1 || j == n-1) {
                std::cout << "* ";
            }
            else std::cout << "  ";
        }
        std::cout << "\n";
    }
}
void pattern22(int n)
{
    for (int i = 0; i < 2*n - 1; i++)
    {
        for (int j = 0; j < 2*n - 1; j++)
        {
            int top = i,
                left = j,
                right = (2*n - 2) - j,
                bottom = (2*n - 2) - i;
            
            int mini = std::min(std::min(top, left), std::min(right, bottom));

            std::cout << n - mini << ' ';
        }
        std::cout << '\n';
    }
}

int main(void)
{
    int n;
    std::cin >> n;
    pattern22(n);
    return 0;
}
