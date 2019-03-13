using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace C_Programming
{
    class Books
    {
        public List<genreList> Genres { get; set; }

        public class genreList
        {
            public List<string> genre { get; set; }
        }

    }
}
