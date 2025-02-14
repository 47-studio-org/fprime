/*
* \author Tim Canham
* \file
* \brief
*
* This file is the test component header for the active rate group unit test.
*
* Code Generated Source Code Header
*
*   Copyright 2014-2015, by the California Institute of Technology.
*   ALL RIGHTS RESERVED. United States Government Sponsorship
*   acknowledged. 
*/

#ifndef PASSIVERATEGROUP_TEST_UT_PASSIVERATEGROUPIMPLTESTER_HPP_
#define PASSIVERATEGROUP_TEST_UT_PASSIVERATEGROUPIMPLTESTER_HPP_

#include <PassiveRateGroupGTestBase.hpp>
#include <Svc/PassiveRateGroup/PassiveRateGroup.hpp>

namespace Svc {

    class PassiveRateGroupTester: public PassiveRateGroupGTestBase {
        public:
            PassiveRateGroupTester(Svc::PassiveRateGroup& inst);
            virtual ~PassiveRateGroupTester();

            void init(NATIVE_INT_TYPE instance = 0);

            void runNominal(U32 contexts[], U32 numContexts, NATIVE_INT_TYPE instance);

        private:

            void from_RateGroupMemberOut_handler(FwIndexType portNum, U32 context);

            Svc::PassiveRateGroup& m_impl;

            void clearPortCalls();

            struct {
                bool portCalled;
                U32 contextVal;
                NATIVE_UINT_TYPE order;
            } m_callLog[Svc::PassiveRateGroupComponentBase::NUM_RATEGROUPMEMBEROUT_OUTPUT_PORTS];

            bool m_causeOverrun; //!< flag to cause an overrun during a rate group member port call
            NATIVE_UINT_TYPE m_callOrder; //!< tracks order of port call.

    };

} /* namespace Svc */

#endif /* PASSIVERATEGROUP_TEST_UT_PASSIVERATEGROUPIMPLTESTER_HPP_ */
