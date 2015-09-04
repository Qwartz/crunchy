/**
* \file ServletIPv6.h
* \brief IPv6 Routing
* \details Contains custom IPv6 routing and segregating code
* \author Corbin Matschull
* \version 1.2
* \date Sep 3. 2015
* \throws CANNOT_BIND_IP_EXCEPTION
*/
#pragma once
namespace crunchy
{
    namespace ipv6
    {
        
        #define __HAS_IPV6_NAMESPACE /**< Use after defining ipv6 namespace elsewhere */
        #define __RETURNS_NULL /**< IP-Object must return null */

        long ipv6_t;

        /**
         * \brief Routing information for IPv6 data
         */
        struct ipv6_routing_routine
        {
            typedef long long ipv6_table[]; /** Define a 128-Bit table array */
            
            
        } ipv6_r_t;

        class ipv6Data
        {
            public:
                long returnDataFromDNS();
        };
    }

}