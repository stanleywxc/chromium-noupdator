// Copyright 2019 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef CHROME_BROWSER_PERFORMANCE_MANAGER_PUBLIC_RENDER_PROCESS_HOST_PROXY_H_
#define CHROME_BROWSER_PERFORMANCE_MANAGER_PUBLIC_RENDER_PROCESS_HOST_PROXY_H_

namespace content {
class RenderProcessHost;
}  // namespace content

namespace performance_manager {

// A RenderProcessHostProxy is used to post messages out of the performance
// manager sequence that are bound for a RenderProcessHost running on the UI
// thread. The object is bound to the UI thread. A RenderProcessHostProxy is
// conceputally equivalent to a WeakPtr<RenderProcessHost>. Copy and assignment
// are explicitly allowed for this object.
class RenderProcessHostProxy {
 public:
  RenderProcessHostProxy();
  RenderProcessHostProxy(const RenderProcessHostProxy& other);
  ~RenderProcessHostProxy();
  RenderProcessHostProxy& operator=(const RenderProcessHostProxy& other);

  // Allows resolving this proxy to the underlying RenderProcessHost. This must
  // only be called on the UI thread. Returns nullptr if the RenderProcessHost
  // no longer exists.
  content::RenderProcessHost* Get() const;

 protected:
  friend class RenderProcessUserData;
  friend class RenderProcessHostProxyTest;

  explicit RenderProcessHostProxy(int render_process_host_id);

 private:
  int render_process_host_id_ = -1;
};

}  // namespace performance_manager

#endif  // CHROME_BROWSER_PERFORMANCE_MANAGER_PUBLIC_RENDER_PROCESS_HOST_PROXY_H_
