#ifndef BOOST_LOG_DEFAULT_DESCRIPTOR_HPP
#define BOOST_LOG_DEFAULT_DESCRIPTOR_HPP

#include "severity.hpp"

namespace boost
{

    namespace log
    {

        template < typename Derived >
        struct default_descriptor
            : public boost::log::severity_attribute< Derived > {

            template < typename MessageDerivation >
            bool validate( boost::log::default_descriptor< MessageDerivation > & message ) const
            {
                return ( message.severity( ) & this->severity( ) ) == message.severity( );
            }

        };

    }

}

#endif
