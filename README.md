# my-kaleidoscope

> Twist a kaleidoscope and one picture shatters into a hundred pieces.
> A compiler does the reverse: it takes the pieces and makes something that runs.

My from-scratch build of Kaleidoscope, the toy language from the LLVM tutorial, written in C++. Started 30 Sep 2026. Seven commits in, and the lexer already has more comments than logic. That's on purpose.

**Status: day one.** Expect rough edges, bugs I haven't found yet, and commit messages with too many exclamation marks.

## The pipeline

Source code goes in one end. Each stage hands something simpler to the next.

| Stage | What it does | Status |
| ----- | ------------ | ------ |
| Lexer | Chops raw characters into tokens | done |
| Parser | Builds an AST from the tokens | Planned |
| Codegen | Turns the AST into LLVM IR | Planned |
| Optimizer | Runs a few LLVM passes over the IR | Planned |
| JIT | Runs the code on the spot | Planned |

## What the lexer sees so far

| Token | Meaning |
| ----- | ------- |
| `tokDef` | the `def` keyword |
| `tokExtern` | the `extern` keyword |
| `tokIdentifier` | names like `foo`, `_bar2` |
| `tokNum` | numbers like `3.14`, stored in `numVal` |
| `tokEof` | end of input |
| anything else | returned as its raw ASCII value (`+`, `(`, `,` ...) |

Comments start with `#` and run to the end of the line.

## The language

Kaleidoscope is small enough to hold in your head. It has functions, `extern`
declarations, floating-point numbers and `#` comments. Later I want to add
control flow and user-defined operators. The syntax below is a sketch and
will shift as the parser takes shape.

```
# a function
def add(a b) a + b

# call something from the C library
extern sin(x)
```

## Build

```bash
clang++ -std=c++17 *.cpp -o kaleidoscope
./kaleidoscope
```

Once codegen lands this will also need LLVM (`llvm-config --cxxflags --ldflags`).
I'll update the instructions when that happens.

## How I'm working

- One stage at a time, in order: lexer, parser, codegen, JIT.
- Commits are prefixed with the stage, like `[lexer]`.
- The comments in the code are notes to myself, and I'm keeping them.
- Bugs are part of the process. If you spot one, open an issue. I'd rather find it early.

## Roadmap

- [x] Working lexer
- [ ] Recursive-descent parser and AST
- [ ] LLVM IR codegen
- [ ] Optimization passes
- [ ] JIT
- [ ] Control flow (`if`, `for`) and user-defined operators

## Credits

Follows the official [LLVM Kaleidoscope tutorial](https://llvm.org/docs/tutorial/).
Mistakes are mine.