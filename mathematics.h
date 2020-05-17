ll gcd(ll x, ll y) {
  return y ? gcd(y, x % y) : x;
}

ll lcm(ll a, ll b)
{
   return a * b / gcd(a, b);
}

hi