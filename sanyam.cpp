#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll find(ll k)
{
  ll len = 1;
  ll ans = 0;
  while (k > 0)
  {
    if (k % 2 && len % 2)
    {
      ans++;
    }
    k /= 2;
    len++;
  }
  return ans;
}
ll solve()
{
  ll k;
  cin >> k;
  ll sum = 0;
  ll i = 1;
  while (sum <= k)
  {
    sum += find(i);
    i++;
  }
  i--;
  return i;
}
int main()
{
  int n;
  cin >> n;
  vector<int> x(n);
  for (int i = 0; i < n; i++)
  {
    cin >> x[i];
  }

  vector<int> y(n);
  for (int i = 0; i < n; i++)
  {
    cin >> y[i];
  }

  cout << square(x, y) << endl;

  return 0;
}

// message to connect (%EMPLOYEE% and %COMPANY% will be replaced with real values)
  const MESSAGE = `Hi %EMPLOYEE%, I am Vaibhav Anand, a junior Computer Engineering undergrad at DTU. I am looking for an SDE Intern at %COMPANY%.
	Are there any work opportunities available matching my interest? I see that you have no such positions advertised at the moment, but thought it would be worth reaching out if there may be any . 
	`;

  // 1. Go to https://www.linkedin.com/company/{COMPANY_NAME}/people/
  // 2. Make sure your LinkedIn is in English
  // 3. Modify the constants to your liking
  // 4. Open chrome dev tools and paste this script or add it as a snippet

(async () => {
  // maximum amount of connection requests
  const MAX_CONNECTIONS = 10;
  // time in ms to wait before requesting to connect
  const WAIT_TO_CONNECT = 2000;
  // time in ms to wait before new employees load after scroll
  const WAIT_AFTER_SCROLL = 3000;
  // message to connect (%EMPLOYEE% and %COMPANY% will be replaced with real values)
  const MESSAGE = `Hi % EMPLOYEE %, I'm a Software Engineer with 4 yrs of experience in full-stack web development.  I see you're currently working at %COMPANY% where I saw a Full Stack job post and was interested to hear more about it.  Would you(or a colleague) have time to chat about the position ? Thanks !Mario`;
  // keywords to filter employees in specific positions
  const POSITION_KEYWORDS = [
    "HR",
    "Recruiter",
    "Hiring",
    "Technical Recruiter",
    "Developer",
    "Software Developer",
  ];

  // <--> //

  const MESSAGE_CHAR_LIMIT = 300;

  function buildMessage(employee)
  {
    const company = document.getElementsByClassName(
                                "org-top-card-summary__title")[0]
                        .title;

    const replacements = {"%COMPANY%" : company, "%EMPLOYEE%" : employee};
    //    const message = MESSAGE.replace(/%\w+%/g, (i) => {
    return replacements[i];
  });

  return message.length <= MESSAGE_CHAR_LIMIT ? message : "";
  }


  function getButtonElements() {
  return [
    ... document.querySelectorAll(
        'button[data-control-name="people_profile_card_connect_button"]'),
  ]
      .filter((button) = > {
        const cardInnerText = button.offsetParent.innerText.split("\n");
        const positionIndex = cardInnerText.length > 3 ? 3 : 1;
        const position = cardInnerText[positionIndex];
        return POSITION_KEYWORDS.some((p) = > position.match(new RegExp(p, "gi")));
      });
  }
