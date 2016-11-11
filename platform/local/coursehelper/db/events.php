<?php
// This file is part of Moodle - http://moodle.org/
//
// Moodle is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// Moodle is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with Moodle.  If not, see <http://www.gnu.org/licenses/>.

/**
 * Definition of core event observers.
 *
 * The observers defined in this file are notified when respective events are triggered. All plugins
 * support this.
 *
 * For more information, take a look to the documentation available:
 *     - Events API: {@link http://docs.moodle.org/dev/Event_2}
 *     - Upgrade API: {@link http://docs.moodle.org/dev/Upgrade_API}
 *
 * @package   core
 * @category  event
 * @copyright 2015 API Worksafe
 * @license   http://www.gnu.org/copyleft/gpl.html GNU GPL v3 or later
 */

defined('MOODLE_INTERNAL') || die();

// List of legacy event handlers.

$handlers = array(
    // No more old events!
);

// List of events_2 observers.

$observers = array(

    array(
        'eventname'   => '\core\event\course_created',
        'callback'    => 'local_coursehelper_observer::course_created',
        'internal'    => false, // This means that we get events only after transaction commit.
    ),
    array(
        'eventname'   => '\core\event\course_updated',
        'callback'    => 'local_coursehelper_observer::course_updated',
        'internal'    => false,
    ),
    array(
        'eventname'   => '\core\event\course_module_created',
        'callback'    => 'local_coursehelper_observer::course_module_created',
        'internal'    => false,
    ),
    array(
        'eventname'   => '\core\event\course_module_updated',
        'callback'    => 'local_coursehelper_observer::course_module_updated',
        'internal'    => false,
    ),
    array(
        'eventname'   => '\mod_quiz\event\attempt_submitted',
        'callback'    => 'local_coursehelper_observer::attempt_submitted',
        'internal'    => false,
    ),
    array(
        'eventname'   => '\mod_quiz\event\attempt_started',
        'callback'    => 'local_coursehelper_observer::attempt_started',
        'internal'    => false,
    ),
    array(
        'eventname'   => '\mod_scorm\event\sco_launched',
        'callback'    => 'local_coursehelper_observer::sco_launched',
        'internal'    => false,
    ),
    /**
     * TO-DO: check these events
     */
    array(
        'eventname'   => '\core\event\course_completed', // ¿?
        'callback'    => 'local_coursehelper_observer::course_completed',
        'internal'    => false,
    ),
    array(
        'eventname'   => '\core\event\course_completion_updated',
        'callback'    => 'local_coursehelper_observer::store',
        'internal'    => false,
    ),
    array(
        'eventname'   => '\core\event\course_module_completion_updated',
        'callback'    => 'local_coursehelper_observer::store',
        'internal'    => false,
    ),
    /*array(
        'eventname'   => '\mod_scorm\event\course_module_viewed', // TO-DO: remove this
        'callback'    => 'local_coursehelper_observer::store',
        'internal'    => false,
    )*/
);

// List of all events triggered by Moodle can be found using Events list report.
