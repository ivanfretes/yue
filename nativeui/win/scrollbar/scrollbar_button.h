// Copyright 2016 Cheng Zhao. All rights reserved.
// Use of this source code is governed by the license that can be found in the
// LICENSE file.

#ifndef NATIVEUI_WIN_SCROLLBAR_SCROLLBAR_BUTTON_H_
#define NATIVEUI_WIN_SCROLLBAR_SCROLLBAR_BUTTON_H_

#include "nativeui/win/scrollbar/repeat_controller.h"
#include "nativeui/win/view_win.h"

namespace nu {

class Scrollbar;

class ScrollbarButton : public ViewImpl {
 public:
  enum Type {
    Up,
    Down,
    Left,
    Right,
  };

  ScrollbarButton(Type type, Scrollbar* scrollbar);
  ~ScrollbarButton() override;

  // ViewImpl:
  void OnMouseEnter() override;
  void OnMouseLeave() override;
  bool OnMouseClick(NativeEvent event) override;
  void Draw(PainterWin* painter, const Rect& dirty) override;

  NativeTheme::ScrollbarArrowExtraParams* params() { return &params_; }

 private:
  void OnClick();

  NativeTheme::ScrollbarArrowExtraParams params_ = {0};

  // The repeat controller that we use to repeatedly click the button when the
  // mouse button is down.
  RepeatController repeater_;

  Type type_;
  Scrollbar* scrollbar_;  // weak ref
};

}  // namespace nu

#endif  // NATIVEUI_WIN_SCROLLBAR_SCROLLBAR_BUTTON_H_
