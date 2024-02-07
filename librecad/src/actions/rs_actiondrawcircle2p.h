/****************************************************************************
**
** This file is part of the LibreCAD project, a 2D CAD program
**
** Copyright (C) 2010 R. van Twisk (librecad@rvt.dds.nl)
** Copyright (C) 2001-2003 RibbonSoft. All rights reserved.
**
**
** This file may be distributed and/or modified under the terms of the
** GNU General Public License version 2 as published by the Free Software 
** Foundation and appearing in the file gpl-2.0.txt included in the
** packaging of this file.
**
** This program is distributed in the hope that it will be useful,
** but WITHOUT ANY WARRANTY; without even the implied warranty of
** MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
** GNU General Public License for more details.
** 
** You should have received a copy of the GNU General Public License
** along with this program; if not, write to the Free Software
** Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
**
** This copyright notice MUST APPEAR in all copies of the script!  
**
**********************************************************************/

#ifndef RS_ACTIONDRAWCIRCLE2P_H
#define RS_ACTIONDRAWCIRCLE2P_H

#include "rs_previewactioninterface.h"

struct RS_CircleData;

/**
 * This action class can handle user events to draw 
 * simple arcs with the center, radius, start- and endangle given.
 *
 * @author Andrew Mustun
 */
class RS_ActionDrawCircle2P : public RS_PreviewActionInterface {
	Q_OBJECT
public:
    /**
     * Action States.
     */
    enum Status {
        SetPoint1,       /**< Setting the 1st point. */
        SetPoint2        /**< Setting the 2nd point. */
    };

public:
    RS_ActionDrawCircle2P(RS_EntityContainer& container,
                          RS_GraphicView& graphicView);
	~RS_ActionDrawCircle2P() override;

    void reset();

	void init(int status=0) override;
	
	void trigger() override;
	void preparePreview();
	
	void mouseMoveEvent(QMouseEvent* e) override;
	void mouseReleaseEvent(QMouseEvent* e) override;
	
	void coordinateEvent(RS_CoordinateEvent* e) override;

	void updateMouseButtonHints() override;
	void updateMouseCursor() override;

protected:
    /**
     * Circle data defined so far.
     */
	std::unique_ptr<RS_CircleData> data;
	struct Points;
	std::unique_ptr<Points> pPoints;
};

#endif
