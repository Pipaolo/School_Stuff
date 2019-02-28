using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _5th_Act
{
    class Items
    {
        public List<string> QuestionsList { get; set; }
        public List<string> Answersheet { get; set; }
        public List<choicesList> ChoicesList { get; set; }

        public class choicesList
        {
            public List<string> choices { get; set; }
        }
    }
}
