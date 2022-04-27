int n, c;
cin >> n >> c;
vector<int> price(n);
vector<int> quantity(n);
for (int i = 0; i < n; i++)
{
    cin >> price[i] >> quantity[i];
}
vector<float> fraction(n);
for (int i = 0; i < n; i++)
{
    fraction[i] = (float)price[i] / (float)quantity[i];
}
sort(fraction.begin(), fraction.end());
float max = 0;
for (int i = 0; i < n; i++)
{
    if (fraction[i] * c > max)
    {
        max = fraction[i] * c;
    }
}
cout << max << endl;