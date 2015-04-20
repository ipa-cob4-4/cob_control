/*!
 *****************************************************************
 * \file
 *
 * \note
 *   Copyright (c) 2015 \n
 *   Fraunhofer Institute for Manufacturing Engineering
 *   and Automation (IPA) \n\n
 *
 *****************************************************************
 *
 * \note
 *   Project name: care-o-bot
 * \note
 *   ROS stack name: cob_control
 * \note
 *   ROS package name: cob_twist_controller
 *
 * \author
 *   Author: Marco Bezzon, email: Marco.Bezzon@ipa.fraunhofer.de
 *
 * \date Date of creation: April, 2015
 *
 * \brief
 *   This header contains the interface description of limiters
 *
 ****************************************************************/
#ifndef LIMITER_CONTAINER_H_
#define LIMITER_CONTAINER_H_

#include "cob_twist_controller/limiters/limiter_base.h"
#include <vector>

/// Container for limiters, implementing interface methods.
class LimiterContainer : public LimiterBase
{
    public:
        /**
         * Specific implementation of enforceLimits-method.
         * See base class LimiterBase for more details on params and returns.
         */
        virtual KDL::JntArray enforceLimits(const KDL::JntArray& q_dot_ik, const KDL::JntArray& q) const;

        /**
         * Initialization for the container.
         */
        void init();

        virtual ~LimiterContainer();

        LimiterContainer(const TwistControllerParams &tcParams, const KDL::Chain &chain)
            : LimiterBase(tcParams, chain)
        {

        }

    protected:
        std::vector<const LimiterBase*> limiters;
        typedef std::vector<const LimiterBase*>::const_iterator limIter;

        /**
         * Add method
         * @param lb An implementation of a limiter.
         */
        void add(const LimiterBase *lb);

        /**
         * Erase all
         */
        void eraseAll();



};

#endif /* LIMITER_CONTAINER_H_ */
