int main()
{
    TEST
    {
        INT(n);
        map<int, vi> mp; // vi 로해야 eb해서 추가시키니까.
        rep(i, n) mp[in()].eb(i + 1);
        for (auto [a, b] : mp) // 맵도 이렇게 가져올수 있더라. a(key)만큼 실행
            if (si(b) == 1)
            { // eb 몇번했는지 확인
                cout << b[0] << endl;
                goto end;
            }
        cout << -1 << endl;
    end:;
    }
}