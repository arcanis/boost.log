#ifndef BOOST_LOG_FILTER_HPP
#define BOOST_LOG_FILTER_HPP

namespace boost
{

    namespace log
    {

        template < class Logger >
        class filter : public Logger::template descriptor< filter< Logger > >::type
        {

        };

    }

}

#endif
