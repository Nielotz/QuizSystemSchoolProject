#ifndef SRC_UI_TEST_TEST_H
#define SRC_UI_TEST_TEST_H

#include <string>
#include <vector>

using namespace std;

namespace UI
{
    namespace Test
    {
        class Test
        {
        public:
            void show_edit_question(string question, vector<string> answers, vector<string> correct_answers);
            void show_review_question(string question, vector<string> answers, vector<string> correct_answers, vector<string> marked_answers);
            void show_take_question(string question, vector<string> answers, vector<string> marked_answers);
        };
    }
}
#endif //SRC_UI_TEST_TEST_H
