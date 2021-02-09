// 게임이론 정리.

// Definition of winning state..  Can it reach the losing state??
// 베라 게임참고,. 0 을 부르면 지고 1,2,3 까지 말할수 있다면..

// nimber also known as grundy num is mex {...}
// mex { ... } where {...} is reachable nimber value
// and mex is smallest positive number NOT IN THE LIST

// cur NUMBER /State / nimber /
//       7       W
//       6       W
//       5       W     n(5) = mex{0,2,3} = 1;
//       4       L     n(4) = mex{1,2,3} = 0;
//       3       W     n(3) = mex{0,1,2} = 3;
//       2       W     n(2) = mex{0,1} = 2;
//       1       W     n(1) = mex{0} = 1;
//       0       L     n(0) = mex{} = 0;

// if nimber value is 0 it is Losing state.
// 따라서 이기기 위해서는 nim이 0인경우는 후공,
// 0이 아닌경우는 선공을 취하면 된다!.

// 분할해서 규칙을 찾아내는 것이 중요하다.
// G = g1 ^ g2 ^ g3 ^ g4 .. 
// 균형상태를 찾아낸다..

// 님게임에서 각 자루에 7 4 2 개가 들어있는경우 다시표현하면
// 7 : 4 + 2 + 1;
// 4 : 4;
// 2 : 2; // 7 ^ 4 ^ 2 = 4 ^ 4 ^ 2 ^ 2 ^ 1;
// 모두 짝수개로 있으면 균형상태(0)이다.
// 따라서 선공이 불균형상태로 만들기때문에 이경우 선공이 진다.
