
// MFC Dialog Application 

// Im Header
	CD2DSolidColorBrush* m_pRedBrush;
	CD2DBrush* m_pWhiteBrush;

// Im constructor

	// Enable D2D support for this window:
	EnableD2DSupport();

	// Initialize D2D resources:
	m_pRedBrush = new CD2DSolidColorBrush(
		GetRenderTarget(),
		D2D1::ColorF(D2D1::ColorF::Red));

	m_pWhiteBrush = new CD2DSolidColorBrush(
		GetRenderTarget(),
		D2D1::ColorF(D2D1::ColorF::White));


// Im custom message handler von AFX_WM_DRAW2D zB OnDraw2d(...)
// zugefügt über Klassenansicht -> 
//					Klassen-Assistent -> 
//						Meldungen -> 
//							Benutzerdefinierte Meldung hinzufügen ->
//								AFX_WM_DRAW2D
//								OnDraw2d
// 						und auf registrierte Meldung klicken

		CHwndRenderTarget* pRenderTarget = (CHwndRenderTarget*)lParam;
		ASSERT_VALID(pRenderTarget);

		CRect rect;
		GetClientRect(rect);

		pRenderTarget->FillRectangle(rect, m_pWhiteBrush);

		CD2DPointF p1{ 0.0,0.0 };
		CD2DPointF p2{ 100.0,100.0 };
		CD2DPointF p3{ 200.0, 75.0 };
		CD2DPointF p4{ 300.0,125.0 };

		pRenderTarget->DrawLine(p1, p2, m_pRedBrush, 0.5, 0);
		pRenderTarget->DrawLine(p2, p3, m_pRedBrush, 0.5, 0);
		pRenderTarget->DrawLine(p3, p4, m_pRedBrush, 0.5, 0);

