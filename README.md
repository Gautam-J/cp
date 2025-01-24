## Competitive Programming Code

Questions from sources:

- [Introduction to Algorithms](https://mitpress.mit.edu/books/introduction-algorithms-third-edition)
- [Cracking The Coding Interview Book](https://www.crackingthecodinginterview.com/)
- [Codeforces](https://codeforces.com/)
- [Leetcode](https://leetcode.com/)
- [Kickstart](https://codingcompetitions.withgoogle.com/kickstart)

> **NOTE**: The Space Complexity provided is the *auxiliary space*.
> Space used to store the input is not considered.

#### Compilation command
```bash
g++ -std=c++17 -fsanitize=address -fsanitize=undefined -Wall -Wshadow -Wno-unused-result -D_GLIBCXX_DEBUG -O2 % -o ./bin/fileName
```

#### Execution command
- Enter the input in `input` file.
- Enter the expected output in `truth` file.
- Create an empty file `output` that will be used to store the output of the program.

```bash
./bin/fileName < input > output && diff output truth -y -W 50
```
