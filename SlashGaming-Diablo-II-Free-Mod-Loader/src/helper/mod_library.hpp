/**
 * SlashGaming Diablo II Free Mod Loader
 * Copyright (C) 2020  Mir Drualga
 *
 * This file is part of SlashGaming Diablo II Free Mod Loader.
 *
 *  This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU Affero General Public License as published
 *  by the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU Affero General Public License for more details.
 *
 *  You should have received a copy of the GNU Affero General Public License
 *  along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 *  Additional permissions under GNU Affero General Public License version 3
 *  section 7
 *
 *  If you modify this Program, or any covered work, by linking or combining
 *  it with Diablo II (or a modified version of that game and its
 *  libraries), containing parts covered by the terms of Blizzard End User
 *  License Agreement, the licensors of this Program grant you additional
 *  permission to convey the resulting work. This additional permission is
 *  also extended to any combination of expansions, mods, and remasters of
 *  the game.
 *
 *  If you modify this Program, or any covered work, by linking or combining
 *  it with any Graphics Device Interface (GDI), DirectDraw, Direct3D,
 *  Glide, OpenGL, or Rave wrapper (or modified versions of those
 *  libraries), containing parts not covered by a compatible license, the
 *  licensors of this Program grant you additional permission to convey the
 *  resulting work.
 *
 *  If you modify this Program, or any covered work, by linking or combining
 *  it with any library (or a modified version of that library) that links
 *  to Diablo II (or a modified version of that game and its libraries),
 *  containing parts not covered by a compatible license, the licensors of
 *  this Program grant you additional permission to convey the resulting
 *  work.
 */

#ifndef SGD2FML_HELPER_MOD_LIBRARY_HPP_
#define SGD2FML_HELPER_MOD_LIBRARY_HPP_

#include <windows.h>

#include <compare>
#include <filesystem>

namespace sgd2fml {

class ModLibrary {
 public:
  ModLibrary() = delete;

  ModLibrary(const std::filesystem::path& library_path);

  ModLibrary(const ModLibrary& mod_library) = delete;
  ModLibrary(ModLibrary&& mod_library) noexcept;

  ~ModLibrary();

  ModLibrary& operator=(const ModLibrary& mod_library) = delete;
  ModLibrary& operator=(ModLibrary&& mod_library) noexcept;

  friend bool operator==(
      const ModLibrary& lhs,
      const ModLibrary& rhs
  ) noexcept;

  friend std::strong_ordering operator<=>(
      const ModLibrary& lhs,
      const ModLibrary& rhs
  ) noexcept;

  const std::filesystem::path& library_path() const noexcept;
  HMODULE module_handle() const noexcept;

 private:
  std::filesystem::path library_path_;
  HMODULE module_handle_;

  explicit ModLibrary(const std::filesystem::path& library_path);

  void (*on_create_window_function_ptr_)(HWND window_handle);
};

} // namespace sgd2fml

#endif /* SGD2FML_HELPER_MOD_LIBRARY_HPP_ */
