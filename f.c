#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <cs50.h>

int main(int argc, string argv[]) //int or string kv
{
    if (argc == 2)
    {
        int length = strlen(argv[1]);

        if (length == 26) // kiểm tra đủ 26 kí tự
        {
            int i = 0, j;

            for (; i < length - 1; ++i)
                for (j = i + 1; j < length; ++j)
                    if (tolower(argv[1][i]) == tolower(argv[1][j]))
                    {
                        i = length; // đặt i và j = length để hủy toàn bộ 2 vòng lặp
                        j = length;
                        break;
                    }

            /*
            nếu i và j chạy hết vòng thử và không có trùng kí tự
            thì j == length và i == length - 1
            tức i + 1 == j
        */
            if (j == i + 1)
            {
                char *str = get_string("plaintext:  ");

                for (i = 0; str[i] != '\0'; ++i) // xâu luôn được kết thúc bởi kí tự '\0'
                {
                    if (isalpha(str[i]))
                    {
                        if (islower(str[i]))
                        {
                            str[i] = tolower(argv[1][str[i] - 97]);
                        }
                        else
                        {
                            str[i] = toupper(argv[1][str[i] - 65]);
                        }
                    }
                }

                printf("ciphertext: %s", str);
                return 0;
            }
        }

        // Xảy ra khi không phát hiện trùng
        printf("Key must contain 26 characters.\n");
        return 1;
    }
    // Xảy ra khi không có tham số
    printf("Usage: %s key\n", argv[0]);
    return 1;
}
