#include <igloo/igloo.h>

using namespace igloo;

Context(GetWords){
    /*
        your test cases here
    */
    Spec(GetFirstWord) {
        Wordle wordle_instance = Wordle("words.txt","allowed.txt");
        std::string word = "aback";
        std::string actual = wordle_instance.get_word(0);
        Assert::That(actual, Equals(word));
    }
    Spec(GetLastWord)
    {
        Wordle wordle_instance = Wordle("words.txt","allowed.txt");
        std::string word = "zonal";
        std::string actual = wordle_instance.get_word(2314);
        Assert::That(actual, Equals(word));
    }
    Spec(GetSomeWord)
    {
        Wordle wordle_instance = Wordle("words.txt","allowed.txt");
        std::string word = "grand";
        std::string actual = wordle_instance.get_word(896);
        Assert::That(actual, Equals(word));   
    }
};
Context(CheckIfWordAllowed)
{
    Spec(IsAllowedAllowed1)
    {
        Wordle wordle_instance = Wordle("words.txt","allowed.txt");
        std::string word = "bider";
        bool actual = wordle_instance.is_word_allowed(word);
        Assert::That(actual, IsTrue());
    }
    Spec(IsWordsAllowed1)
    {
        Wordle wordle_instance = Wordle("words.txt","allowed.txt");
        std::string word = "spray";
        bool actual = wordle_instance.is_word_allowed(word);
        Assert::That(actual, IsTrue());
    }
    Spec(IsNotAllowed1)
    {
        Wordle wordle_instance = Wordle("words.txt","allowed.txt");
        std::string word = "xxxxx";
        bool actual = wordle_instance.is_word_allowed(word);
        Assert::That(actual, IsFalse());
    }
};
Context(CheckGuess)
{
    Spec(CheckGuessBlank)
    {
        std::string rword = "weary";
        std::string gword = "blink";
        std::vector<int> expected{0,0,0,0,0};
        std::vector<int> actual = Wordle::check_word(rword,gword);
        Assert::That(actual, Equals(expected));
    }
    Spec(CheckGuessExact)
    {
        std::string rword = "bingo";
        std::string gword = "bingo";
        std::vector<int> expected{2,2,2,2,2};
        std::vector<int> actual = Wordle::check_word(rword,gword);
        Assert::That(actual, Equals(expected));
    }
    Spec(CheckGuessMixed1)
    {
        std::string rword = "magic";
        std::string gword = "marri";
        std::vector<int> expected{2,2,0,0,1};
        std::vector<int> actual = Wordle::check_word(rword,gword);
        Assert::That(actual, Equals(expected));  
    }
    Spec(CheckGuessMixed2)
    {
        std::string rword = "loser";
        std::string gword = "shoes";
        std::vector<int> expected{1,0,1,2,1};
        std::vector<int> actual = Wordle::check_word(rword,gword);
        Assert::That(actual, Equals(expected));  
    }
};
Context(WordleGameTest)
{
    Spec(IsInitCorrect)
    {
        std::string expected = "abate";
        Wordle wordle_instance = Wordle("words.txt","allowed.txt");
        wordle_instance.start_game(2);
        std::string actual = wordle_instance.current_game_word;
        Assert::That(actual, Equals(expected));
    }
    Spec(RejectGuess)
    {
        Wordle wordle_instance = Wordle("words.txt","allowed.txt");
        wordle_instance.start_game(7);
        int actual = wordle_instance.guess_word("zzzzx");
        Assert::That(actual, Equals(2));
    }
    Spec(CorrectGuess)
    {
        Wordle wordle_instance = Wordle("words.txt","allowed.txt");
        wordle_instance.start_game(8);
        int actual = wordle_instance.guess_word("abode");
        Assert::That(actual, Equals(1));
    }
    Spec(IncorrectGuess)
    {
        Wordle wordle_instance = Wordle("words.txt","allowed.txt");
        wordle_instance.start_game(8);
        int actual = wordle_instance.guess_word("armed");
        int a_state = wordle_instance.get_letter_state('a');
        int r_state = wordle_instance.get_letter_state('r');
        int m_state = wordle_instance.get_letter_state('m');
        int e_state = wordle_instance.get_letter_state('e');
        int d_state = wordle_instance.get_letter_state('d');
        Assert::That(actual, Equals(0));
        Assert::That(a_state,Equals(Wordle::FOUND));
        Assert::That(r_state,Equals(Wordle::NOT_IN_WORD));
        Assert::That(m_state,Equals(Wordle::NOT_IN_WORD));
        Assert::That(e_state,Equals(Wordle::IN_WORD));
        Assert::That(d_state,Equals(Wordle::IN_WORD));
    }
};

int main(int argc, const char* argv[]){
    return TestRunner::RunAllTests(argc, argv);
}
