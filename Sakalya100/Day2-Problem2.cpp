//Longest Bracket Sequence
void update(int tmp, int &len, int &cnt)
{
    if (tmp > len)
    {
        len = tmp;
        cnt = 1;
    }
    else if (tmp == len)
    {
        cnt++;
    }
}

void solve(string s)
{
    int f[s.size() + 1], second[s.size() + 1], top;

    int n = s.size();
    int len = 0, cnt = 1;
    if (n == 0)
    {
        puts("0 1");
        return;
    }

    top = 0;
    for (int i = 0; i < n; ++i)
    {
        if (s[i] == '(')
        {
            second[top++] = i;
            f[i] = 0;
        }
        else
        {
            if (top == 0)
            {
                f[i] = 0;
            }
            else
            {
                int k = second[--top], tmp = 0;
                if (k > 0)
                {
                    tmp = i - k + 1 + f[k - 1];
                }
                else
                {
                    tmp = i - k + 1;
                }

                f[i] = tmp;

                update(tmp, len, cnt);
            }
        }
    }

    cout << len << " " << cnt;
}